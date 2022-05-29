// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file defines a state machine where clients can induce changes via invocation of external events.
//				The Manager essentially performs the actual business logic work.

#include <mutex>
#include "manager.h"

using namespace std;
using namespace dds_msgs;

// Constructor reads configuration information, initializes DDS communicator and TCP client
Manager::Manager(std::string sentinel) :
	StateMachine(NUM_OF_STATES, INITIALIZATION_STATE),
	m_constructor_success_flag(false),
	m_ui_cmd_cnt(0), 
	m_jpeg_generation_liveness_msg_cnt(0),
	
	m_get_drone_scan_route_msg_cnt(0),
	m_start_jpeg_generation_msg_cnt(0),
	m_stop_jpeg_generation_msg_tx_cnt(0),
	m_start_model_generation_msg_cnt(0),
	m_upload_curr_model_to_cloud_msg_cnt(0),
	m_upload_diff_model_to_cloud_msg_cnt(0),
	m_request_ref_model_msg_cnt(0),
	m_sentinel(sentinel),
    m_model_type(NEW_MODEL)
{
	Json::Value root;
	Json::Reader reader;
	ifstream config_file;

	// Create new logger file for logging all events	
	stringstream manager_log_path;
	manager_log_path << SolutionDir << "logs\\manager_log_" + m_event_logger.Get_Timestamp_File() + ".txt";
	m_event_logger.Start(manager_log_path.str(), "Geo Comp Manager event logger is started");
	
	// Create new logger file for logging platform location message contents
	stringstream platform_location_log_path;
	platform_location_log_path << SolutionDir << "logs\\platform_location_log_" + m_platform_location_logger.Get_Timestamp_File() + ".txt";
	m_platform_location_logger.Start(platform_location_log_path.str(), "Platform Location event logger is started");
	m_platform_location_queue.push("Lat	Lon	Alt");

	// Re-assign threads
	m_event_thread = std::thread(&Manager::LogEvent, this, m_sentinel);
	m_platform_location_thread = std::thread(&Manager::LogPlatformLocation, this, m_sentinel);

	// Open pre-defined DDS configuration file for reading DDS configuration information
	stringstream config_dds_path;
	config_dds_path << SolutionDir << "config\\config_dds.json";
	config_file.open(config_dds_path.str(), ios::in);

	// Read information from DDS configuration file in JSON format and store it in root
	bool init_flag = reader.parse(config_file, root);
    config_file.close();

	if (init_flag)
	{
		// Store read initializations parameters in the local structure
		m_dds_comm_init_params.domain_id = root["domain_id"].asInt();											// 66;
		m_dds_comm_init_params.communicator_name.assign(root["communicator_name"].asString());					// "WorldPerception";
		m_dds_comm_init_params.qos_default_library_name.assign(root["qos_default_library_name"].asString());	// "WorldPerceptionQoS";
		//m_dds_comm_init_params.qos_default_profile_name;														// nothing
		stringstream config_qos_path;
		config_qos_path << SolutionDir << "config\\" << "USER_QOS_PROFILES.xml";
		m_dds_comm_init_params.qos_xml_uri.assign(config_qos_path.str());

		// Initialize DDS communicator
		init_flag = m_dds_comm.Init(m_dds_comm_init_params);
	}

	// Create DDS readers
	if (init_flag)
	{
		m_dds_comm.RegisterOnData<MissionPlanMsg>("MissionPlanMsg", std::bind(&Manager::MissionPlanMsgCb, this, std::placeholders::_1, std::placeholders::_2));
		m_dds_comm.RegisterOnData<DroneScanRouteMsg>("DroneScanRouteMsg", std::bind(&Manager::DroneScanRouteMsgCb, this, std::placeholders::_1, std::placeholders::_2));
		m_dds_comm.RegisterOnData<PlatformLocationMsg>("PlatformLocationMsg", std::bind(&Manager::PlatformLocationMsgCb, this, std::placeholders::_1, std::placeholders::_2));
		m_dds_comm.RegisterOnData<ReportJpegGenerationLivenessMsg>("ReportJpegGenerationLivenessMsg", std::bind(&Manager::ReportJpegGenerationLivenessMsgCb, this, std::placeholders::_1, std::placeholders::_2));
		m_dds_comm.RegisterOnData<BaseMsg>("EndMissionMsg", std::bind(&Manager::EndMissionMsgCb, this, std::placeholders::_1, std::placeholders::_2));
		m_dds_comm.RegisterOnData<BaseMsg>("UserInputMsg", std::bind(&Manager::UserInputMsgCb, this, std::placeholders::_1, std::placeholders::_2));
	}

	// Create DDS writers
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<GetDroneScanRouteMsg>("GetDroneScanRouteMsg") != nullptr)) ? true : false;
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<DroneScanRouteMsg>("DroneScanRouteMsg") != nullptr)) ? true : false;
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<PlatformLocationMsg>("PlatformLocationMsg") != nullptr)) ? true : false;
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<StartJpegGenerationMsg>("StartJpegGenerationMsg") != nullptr)) ? true : false;
    init_flag = ((init_flag) && (m_dds_comm.CreateWriter<StopJpegGenerationMsg>("StopJpegGenerationMsg") != nullptr)) ? true : false;
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<DoubleUrlMsg>("UploadCurrModelMsg") != nullptr)) ? true : false;
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<DoubleUrlMsg>("UploadDiffModelMsg") != nullptr)) ? true : false;
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<DoubleUrlMsg>("RequestRefModelMsg") != nullptr)) ? true : false;

	if (init_flag)
	{
		// MJ TODO: Commented out for the purpose of integration with COMMIT
		// Open pre-defined TCP configuration file for reading TCP configuration information
		stringstream config_tcp_path;
		config_tcp_path << SolutionDir << "config\\config_tcp.json";
		config_file.close();
		config_file.open(config_tcp_path.str(), ios::in);

		// Read configuration information from TCP configuration file in JSON format and store it in root
		init_flag = reader.parse(config_file, root);
        config_file.close();
		
		if (init_flag)
		{			
			// Store read initializations parameters in the configuration structure
			m_tcp_client_sightec.Set_Server_IP(root["server_ip_sightec"].asString());			// "127.0.0.1";
			m_tcp_client_sightec.Set_Server_Port(root["server_port_sightec"].asInt());			// 5678
		}
	}

	if (init_flag == true)
	{
		m_constructor_success_flag = true;
		m_event_queue.push("Constructor success");
	}
	else
	{
		m_constructor_success_flag = false;
		m_event_queue.push("Constructor error");

		Stop();
	}
}

// This function starts the execution of the manager (enters the state machine)
void Manager::Start(void)
{
	/// BEGIN_TRANSITION_MAP starts the map. 
	/// Each TRANSITION_MAP_ENTRY that follows indicates what the state machine should do based upon the current state. 
	/// The number of entries in each transition map table must match the number of state functions exactly. 
	/// Since we have 9 state functions, we need 9 entries. 
	/// The location of each entry matches the order of state functions defined within the state map. 
	/// Thus, the first entry within the Init() function indicates an EVENT_IGNORED as shown below.
		BEGIN_TRANSITION_MAP			              	/// Current State:
			TRANSITION_MAP_ENTRY(INITIALIZATION_STATE)	/// INITIALIZATION_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// MISSION_PLAN_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// GET_DRONE_SCAN_ROUTE_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// DRONE_SCAN_ROUTE_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// START_JPEG_GENERATION_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// STOP_JPEG_GENERATION_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// MODEL_GENERATION_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// MODEL_UPLOAD_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// MODEL_REFERENCE_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// MISSION_END_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)			/// FINALIZATION_STATE - If a Start event occurs while the current state is Finalization_State, then transition to state Initialization_State.
		END_TRANSITION_MAP(NULL)

		/// END_TRANSITION_MAP terminates the map. 
		/// The argument to this end macro is the event data, if any. 
		/// Start() has no event data so the argument is NULL.
}

// This function stops the execution of the manager (leaves the state machine)
void Manager::Stop(void)
{
	BEGIN_TRANSITION_MAP								/// Current State:
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// INITIALIZATION_STATE - If a Stop event occurs while the current state is 'any state', then transition to state Finalization_State.
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// MISSION_PLAN_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// GET_DRONE_SCAN_ROUTE_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// DRONE_SCAN_ROUTE_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// START_JPEG_GENERATION_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// STOP_JPEG_GENERATION_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// MODEL_GENERATION_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// MODEL_UPLOAD_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// MODEL_REFERENCE_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)		/// MISSION_END_STATE
		TRANSITION_MAP_ENTRY(EVENT_IGNORED)				/// FINALIZATION_STATE
	END_TRANSITION_MAP(NULL)
}

void Manager::LogEvent(std::string sentinel)
{
	while (true)
	{
        std::string msg;

		msg.assign(m_event_queue.pop());

        if (msg.compare(sentinel) != 0)
		{
            m_event_logger.Print(msg);
		}
        else
        {
            m_event_logger.Close("Geo Comp Manager event logger is closed");
            break;
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

void Manager::LogPlatformLocation(std::string sentinel)
{
    while (true)
    {
        std::string msg;

        msg.assign(m_platform_location_queue.pop());

        if (msg.compare(sentinel) != 0)
        {
            m_platform_location_logger.Print_Location(msg);
        }
        else
        {
            m_platform_location_logger.Close("Platform Location event logger is closed");
            break;
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

// AirBuild/AirDiff sequences
//  - This is the state machine entry point that starts a new state machine cycle
STATE_DEFINE(Manager, Initialization_State, NoEventData)
{
	m_event_queue.push("Initialization_State entry");

	if (m_constructor_success_flag == true)
	{
		m_event_queue.push("Initialization_State exit");
		InternalEvent(MISSION_PLAN_STATE);
	}
	else
	{
		m_event_queue.push("Initialization_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// AirBuild/AirDiff sequences
//  - Receives MissionPlanMsg (1) (DDS) from Geo Comp Mission Broadcaster (COMMIT)
//  - Validates message contents
STATE_DEFINE(Manager, Mission_Plan_State, NoEventData)
{
	m_event_queue.push("Mission_Plan_State entry");

	bool valid_param_flag = true;

	// Wait to receive a new MissionPlanMsg
	m_mission_plan_msg = m_mission_plan_queue.pop();

	if (m_mission_plan_msg.MissionName().empty())
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Mission name is empty!");
	}

	if ((m_mission_plan_msg.MissionType() < dds_msgs::EnumMission::AirBuild) ||
		(m_mission_plan_msg.MissionType() > dds_msgs::EnumMission::GroundDiff))
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Mission type is invalid!");
	}

	if ((m_mission_plan_msg.PlatformType() < dds_msgs::EnumPlatform::Drone) ||
		(m_mission_plan_msg.PlatformType() > dds_msgs::EnumPlatform::UGV))
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Platform type is invalid!");
	}

	switch (m_mission_plan_msg.MissionType())
	{
		case dds_msgs::EnumMission::AirBuild:
		case dds_msgs::EnumMission::AirDiff:

			if ((m_mission_plan_msg.ScanType() < dds_msgs::EnumScan::Rectangular) ||
				(m_mission_plan_msg.ScanType() > dds_msgs::EnumScan::LocalSquare))
			{
				valid_param_flag = false;
				m_event_queue.push("ERROR: Scan type is invalid!");
			}

		case dds_msgs::EnumMission::GroundBuild:
		case dds_msgs::EnumMission::GroundDiff:

			if (m_mission_plan_msg.ScanType() != dds_msgs::EnumScan::None)
			{
				valid_param_flag = false;
				m_event_queue.push("ERROR: Scan type is invalid!");
			}

		default:

			// Cannot happen due to error checking above 
			break;
	}

	if ((m_mission_plan_msg.ScanArea().size() < 3) || (m_mission_plan_msg.ScanArea().size() > 3))
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Scan area size is invalid!");
	}
	else if (m_mission_plan_msg.ScanArea().size() == 3)
	{
		// Validate each object parameter in the array of 3 GeoPoint objects
		for (unsigned int ii = 0; ii < m_mission_plan_msg.ScanArea().size(); ii++)
		{
			dds_msgs::GeoPoint geo_point = m_mission_plan_msg.ScanArea().at(ii);

			// Validate first geo point data
			if (ii == 0)
			{
				if ((geo_point.Lat() < -90.0) || (geo_point.Lat() > 90.0))
				{
					valid_param_flag = false;
					m_event_queue.push("ERROR: Scan area geo point latitude is invalid!");
				}

				if ((geo_point.Lon() < -180.0) || (geo_point.Lon() > 180.0))
				{
					valid_param_flag = false;
					m_event_queue.push("ERROR: Scan area geo point longitude is invalid!");
				}

				if ((geo_point.Alt() < -432.0) || (geo_point.Alt() > 1500.0))
				{
					valid_param_flag = false;
					m_event_queue.push("ERROR: Scan area geo point altitude is invalid!");
				}
			}

			// Validate second geo point data
			if (ii == 1)
			{
				double radius = geo_point.Lat();
				unsigned short num_of_points = geo_point.Lon();

				if ((radius < 20.0) || (radius > 200.0))
				{
					valid_param_flag = false;
					m_event_queue.push("ERROR: Scan area radius is invalid!");
				}

				if ((num_of_points < 40) || (num_of_points > 360) || ((num_of_points % 4) != 0))
				{
					valid_param_flag = false;
					m_event_queue.push("ERROR: Scan area number of points value is invalid!");
				}

			}
		}
	}

	if (m_mission_plan_msg.GeoPathCurrModel().empty())
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Geo path current model is empty");
	}

	if (m_mission_plan_msg.CloudUrlCurrModel().empty())
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Cloud URL current model is empty");
	}

	if (valid_param_flag == true)
	{
		m_model_type = NEW_MODEL;
		m_event_queue.push("Mission_Plan_State exit");

		switch (m_mission_plan_msg.MissionType())
		{
			case dds_msgs::EnumMission::AirBuild:
			case dds_msgs::EnumMission::AirDiff:
	
				InternalEvent(GET_DRONE_SCAN_ROUTE_STATE);
				break;

			case dds_msgs::EnumMission::GroundBuild:
			case dds_msgs::EnumMission::GroundDiff:

				InternalEvent(START_JPEG_GENERATION_STATE);
				break;

			default:

				// Cannot happen due to error checking above 
				break;
		}
	}
	else
	{
		m_event_queue.push("Mission_Plan_State error");
		m_event_queue.push("Remaining in Mission_Plan_State");
		InternalEvent(MISSION_PLAN_STATE);
	}
}

// AirBuild/AirDiff sequences
//  - Constructs GetDroneScanRouteMsg (2), fills it out with information extracted from MissionPlanMsg (1)
//  - Sends GetDroneScanRouteMsg (2) (DDS) to Geo Comp Flight Plan Service (Elta)
STATE_DEFINE(Manager, Get_Drone_Scan_Route_State, NoEventData)
{
	m_event_queue.push("Get_Drone_Scan_Route_State entry");

	// Compose DDS message
	m_get_drone_scan_route_msg.MsgId(2);
	m_get_drone_scan_route_msg.MsgCount(++m_get_drone_scan_route_msg_cnt);
	m_get_drone_scan_route_msg.MissionId(m_mission_plan_msg.MissionId());
	m_get_drone_scan_route_msg.ScanType(m_mission_plan_msg.ScanType());

	m_get_drone_scan_route_msg.ScanArea().clear();
	m_get_drone_scan_route_msg.ScanArea().shrink_to_fit();
    for (unsigned int ii = 0; ii < m_mission_plan_msg.ScanArea().size(); ii++)
		m_get_drone_scan_route_msg.ScanArea().push_back(m_mission_plan_msg.ScanArea().at(ii));

	m_get_drone_scan_route_msg.ScanAreaGroundAvgAlt(m_mission_plan_msg.ScanAreaGroundAvgAlt());
	m_get_drone_scan_route_msg.FlightAltAboveGroundAvgAlt(m_mission_plan_msg.FlightAltAboveGroundAvgAlt());
	m_get_drone_scan_route_msg.TakeoffAltAboveSeaLevel(m_mission_plan_msg.TakeoffAltAboveSeaLevel());
	m_get_drone_scan_route_msg.FlightSpeed(m_mission_plan_msg.FlightSpeed());
	m_get_drone_scan_route_msg.CameraHorizontalFOV(m_mission_plan_msg.CameraHorizontalFOV());
	m_get_drone_scan_route_msg.CameraVerticalFOV(m_mission_plan_msg.CameraVerticalFOV());
	m_get_drone_scan_route_msg.CameraHorizontalResolution(m_mission_plan_msg.CameraHorizontalResolution());
	m_get_drone_scan_route_msg.CameraVerticalResolution(m_mission_plan_msg.CameraVerticalResolution());
	m_get_drone_scan_route_msg.OverlapInFlightDirection(m_mission_plan_msg.OverlapInFlightDirection());
	m_get_drone_scan_route_msg.OverlapInLateralDirection(m_mission_plan_msg.OverlapInLateralDirection());
	m_get_drone_scan_route_msg.GimbalPitchAngle(m_mission_plan_msg.GimbalPitchAngle());
	m_get_drone_scan_route_msg.SquareCenter(m_mission_plan_msg.SquareCenter());
	m_get_drone_scan_route_msg.SquareSide(m_mission_plan_msg.SquareSide());

	// Send DDS message
	if (m_dds_comm.Write<GetDroneScanRouteMsg>("GetDroneScanRouteMsg", m_get_drone_scan_route_msg))
	{
		std::stringstream ss;
        ss << "Send GetDroneScanRouteMsg (2) (DDS) to Geo Comp Flight Plan Service (Elta): "
			<< m_get_drone_scan_route_msg.MsgCount();
		m_event_queue.push(ss.str());

		m_event_queue.push("Get_Drone_Scan_Route_State exit");
		InternalEvent(DRONE_SCAN_ROUTE_STATE);
	}
	else
	{
		m_event_queue.push("Get_Drone_Scan_Route_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// AirBuild/AirDiff sequences
//  - Receives DroneScanRouteMsg (3) (DDS) from Geo Comp Flight Plan Service (Elta)
//  - Sends DroneScanRouteMsg (3) (DDS) to:
//      Geo Comp Mission Broadcaster (COMMIT)
//      Geo Comp JPEG Generator (TES)
STATE_DEFINE(Manager, Drone_Scan_Route_State, NoEventData)
{
	m_event_queue.push("Drone_Scan_Route_State entry");

	// Wait to receive a new DroneScanRouteMsg
	m_drone_scan_route_msg = m_drone_scan_route_queue.pop();

    m_event_queue.push("Drone_Scan_Route_State exit");
    InternalEvent(START_JPEG_GENERATION_STATE);
}

// AirBuild/AirDiff sequences
//  - Receives user input to start JPEG generation
//  - Sends StartJpegGenerationMsg (5) (DDS) to Geo Comp JPEG Generator (TES)
STATE_DEFINE(Manager, Start_Jpeg_Generation_State, NoEventData)
{
	m_event_queue.push("Start_Jpeg_Generation_State entry");

	// Wait for a UI command to compose and send StartJpegGenerationMsg
	m_start_jpeg_generation_queue.pop();

	// Compose DDS message
	m_start_jpeg_generation_msg.MsgId(5);
	m_start_jpeg_generation_msg.MsgCount(++m_start_jpeg_generation_msg_cnt);
	m_start_jpeg_generation_msg.MissionId(m_mission_plan_msg.MissionId());
	m_start_jpeg_generation_msg.PlatformType(m_mission_plan_msg.PlatformType());
	m_start_jpeg_generation_msg.GeoPathJpegFiles(m_mission_plan_msg.GeoPathJpegFiles().value());

	// Send DDS message
	if (m_dds_comm.Write<StartJpegGenerationMsg>("StartJpegGenerationMsg", m_start_jpeg_generation_msg))
	{
		std::stringstream ss;
        ss << "Send StartJpegGenerationMsg (5) to (DDS) Geo Comp JPEG Generator (TES): "
			<< m_start_jpeg_generation_msg.MsgCount();
		m_event_queue.push(ss.str());

		m_event_queue.push("Start_Jpeg_Generation_State exit");
		InternalEvent(STOP_JPEG_GENERATION_STATE);
	}
	else
	{
		m_event_queue.push("Start_Jpeg_Generation_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// AirBuild/AirDiff sequences
//  - Receives user input to start model generation
//  - Sends StopJpegGenerationMsg (51) (DDS) to Geo Comp JPEG Generator (TES)
STATE_DEFINE(Manager, Stop_Jpeg_Generation_State, NoEventData)
{
	m_event_queue.push("Stop_Jpeg_Generation_State entry");

	// Wait for a UI command to stop JPEG generation and start model generation
	m_stop_jpeg_generation_queue.pop();

	// Compose DDS message
	m_stop_jpeg_generation_msg.MsgId(51);
	m_stop_jpeg_generation_msg.MsgCount(++m_stop_jpeg_generation_msg_tx_cnt);
	m_stop_jpeg_generation_msg.MissionId(m_mission_plan_msg.MissionId());

	// Send DDS message
    if (m_dds_comm.Write<StopJpegGenerationMsg>("StopJpegGenerationMsg", m_stop_jpeg_generation_msg))
	{
		std::stringstream ss;
        ss << "Send StopJpegGenerationMsg (51) (DDS) to Geo Comp JPEG Generator (TES): "
			<< m_stop_jpeg_generation_msg.MsgCount();
		m_event_queue.push(ss.str());

		m_event_queue.push("Stop_Jpeg_Generation_State exit");
		InternalEvent(MODEL_GENERATION_STATE);
	}
	else
	{
		m_event_queue.push("Stop_Jpeg_Generation_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// AirBuild/AirDiff sequences
//  - Sends StartModelGenerationMsg (7) to Geo Comp DSM App (Sightec) (TCP)
//  - Receives ReportModelGenerationMsg (8) from Geo Comp DSM App (Sightec) (TCP)
// 
// Note: While the ReportModelGenerationMsg (8) is acyclical in nature, it sends its status periodically which requires
// it to be processed until a certain keyword (TBD) is received
STATE_DEFINE(Manager, Model_Generation_State, NoEventData)
{			
	m_event_queue.push("Model_Generation_State entry");

	bool comm_error_flag = false;
	bool valid_param_flag = true;
	unsigned char init_comm_cnt = 0;
    const unsigned char num_of_attempts_to_connect = 10;

	// Initialize TCP client
	if (m_tcp_client_sightec.IsInit() == false)
	{
		do
		{
			if (m_tcp_client_sightec.Init())
			{
				m_event_queue.push("Communication with Sightec has been established");
				break;
			}
			else
			{
				init_comm_cnt++;
                std::this_thread::sleep_for(std::chrono::seconds(1));
			}

            if (init_comm_cnt >= num_of_attempts_to_connect)
			{
				m_event_queue.push("Failed to establish communication with Sightec");
				break;
			}

		} while (true);
	}

    if (init_comm_cnt < num_of_attempts_to_connect)
	{
		if (m_mission_plan_msg.GeoPathJpegFiles().value().empty())
		{
			valid_param_flag = false;
			m_event_queue.push("ERROR: Geo path JPEG files is empty");
		}

		if (m_mission_plan_msg.GeoPathRefModel().value().empty())
		{
			valid_param_flag = false;
			m_event_queue.push("ERROR: Geo path reference model is empty");
		}

		if (m_mission_plan_msg.GeoPathDiffModel().value().empty())
		{
			valid_param_flag = false;
			m_event_queue.push("ERROR: Cloud URL difference model is empty");
		}

		if (valid_param_flag == true)
		{
            // Compose StartModelGenerationMsg (7) payload in JSON format
			Json::Value root;
			root["MsgId"] = 7;
			root["MsgCount"] = ++m_start_model_generation_msg_cnt;
			root["MissionId"] = m_mission_plan_msg.MissionId();
			root["ModelType"] = m_model_type;
			root["GeoPathJpegFiles"] = m_mission_plan_msg.GeoPathJpegFiles().value();
			root["GeoPathCurrModel"] = m_mission_plan_msg.GeoPathCurrModel();
			root["GeoPathRefModel"] = m_mission_plan_msg.GeoPathRefModel().value();
			root["GeoPathDiffModel"] = m_mission_plan_msg.GeoPathDiffModel().value();
			
			Json::FastWriter fast_writer;
			std::string StartModelGenerationMsg = fast_writer.write(root);

			//Json::StyledWriter styled_writer;
			//std::string StartModelGenerationMsg = styled_writer.write(root);

            if (m_tcp_client_sightec.Send(StartModelGenerationMsg) == true)
			{
				m_event_queue.push("Send StartModelGenerationMsg (7) to Geo Comp DSM App (Sightec) (TCP)");
			}
			else
			{
                m_event_queue.push("ERROR: Failed to send StartModelGenerationMsg (7) to Geo Comp DSM App (Sightec) (TCP)");
			}

            std::string rx_msg, status;

			do
			{
                int num_of_rx_bytes = m_tcp_client_sightec.Receive(rx_msg);

				// MJ TODO: Confirm with Sightec status and termination procedure / keywords
				if (num_of_rx_bytes < 0)
				{
					m_event_queue.push("Model_Generation_State error");
					m_event_queue.push("ERROR: Communication with Geo Comp DSM App (Sightec) (TCP) failed");
					status.assign(m_sentinel);
					comm_error_flag = true;
				}
				else if (num_of_rx_bytes == 0)
				{
					m_event_queue.push("Model_Generation_State error");
					m_event_queue.push("ERROR: Communication with Geo Comp DSM App (Sightec) (TCP) has been terminated");
					status.assign(m_sentinel);
					comm_error_flag = true;
				}
				else
				{
					m_event_queue.push("Receive ReportModelGenerationMsg (8) from Geo Comp DSM App (Sightec) (TCP)");

                    Json::Value root;
                    Json::Reader reader;
                    bool parse_flag = reader.parse(rx_msg, root);

                    if (parse_flag == true)
                    {
                        //unsigned short msg_id = root["MsgId"].asUInt();
                        //unsigned short msg_cnt = root["MsgCount"].asUInt();
                        //unsigned short mission_id = root["MissionId"].asUInt();
                        status = root["Status"].asString();
                        //unsigned short error_code = root["ErrorCode"].asUInt();

                        stringstream ss;
                        ss << "ReportModelGenerationMsg (8) status: " << status;
                        m_event_queue.push(ss.str());
                    }
                    else
                    {
                        stringstream ss;
                        ss << "ERROR: ReportModelGenerationMsg (8) bad format";
                        m_event_queue.push(ss.str());
                    }
				}

			} while (status.compare(m_sentinel) != 0);

			m_tcp_client_sightec.Close();

			if (comm_error_flag == true)
			{
				m_event_queue.push("Model_Generation_State error");
				InternalEvent(FINALIZATION_STATE);
			}
			else
			{
				m_event_queue.push("Model_Generation_State exit");
				InternalEvent(MODEL_UPLOAD_STATE);
			}
		}
		else
		{
			m_event_queue.push("Model_Generation_State error");
			InternalEvent(FINALIZATION_STATE);
		}
	}
	else
	{
		m_event_queue.push("Model_Generation_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// AirBuild/GroundBuild sequence
//  - Sends UploadCurrModelMsg (91) (DDS) to Geo Comp LAS Service (COMMIT)
//  - Transitions to Mission_End_State

// AirDiff/GroundDiff sequence (m_model_type = NEW_MODEL)
//  - Transitions to Model_Reference_State

// AirDiff/GroundDiff sequence (m_model_type = DIFF_ANALYSIS)
//  - Sends UploadDiffModelMsg (92) (DDS) to Geo Comp LAS Service (COMMIT)
//  - Transitions to Mission_End_State
STATE_DEFINE(Manager, Model_Upload_State, NoEventData)
{
	m_event_queue.push("Model_Upload_State entry");

	switch (m_mission_plan_msg.MissionType())
	{
		case dds_msgs::EnumMission::AirBuild:
        case dds_msgs::EnumMission::GroundBuild:

			// Compose DDS message
			m_upload_model_to_cloud_msg.MsgId(91);
			m_upload_model_to_cloud_msg.MsgCount(++m_upload_curr_model_to_cloud_msg_cnt);
			m_upload_model_to_cloud_msg.MissionId(m_mission_plan_msg.MissionId());
			m_upload_model_to_cloud_msg.GeoPath(m_mission_plan_msg.GeoPathCurrModel());
			m_upload_model_to_cloud_msg.CloudUrl(m_mission_plan_msg.CloudUrlCurrModel());

			// Send DDS message
			if (m_dds_comm.Write<DoubleUrlMsg>("UploadCurrModelMsg", m_upload_model_to_cloud_msg))
			{
				std::stringstream ss;
                ss << "Send UploadCurrModelMsg (91) (DDS) to Geo Comp LAS Service (COMMIT): "
					<< m_upload_model_to_cloud_msg.MsgCount();
				m_event_queue.push(ss.str());

				m_event_queue.push("Model_Upload_State exit");
				InternalEvent(MISSION_END_STATE);
			}
			else
			{
				m_event_queue.push("Model_Upload_State error");
				InternalEvent(FINALIZATION_STATE);
			}

			break;

		case dds_msgs::EnumMission::AirDiff:
        case dds_msgs::EnumMission::GroundDiff:

			switch (m_model_type)
			{
				case NEW_MODEL:

					// Compose DDS message
					m_upload_model_to_cloud_msg.MsgId(91);
					m_upload_model_to_cloud_msg.MsgCount(++m_upload_curr_model_to_cloud_msg_cnt);
					m_upload_model_to_cloud_msg.MissionId(m_mission_plan_msg.MissionId());
					m_upload_model_to_cloud_msg.GeoPath(m_mission_plan_msg.GeoPathCurrModel());
					m_upload_model_to_cloud_msg.CloudUrl(m_mission_plan_msg.CloudUrlCurrModel());

					// Send DDS message
					if (m_dds_comm.Write<DoubleUrlMsg>("UploadCurrModelMsg", m_upload_model_to_cloud_msg))
					{
						// Update model type for the second entrance to this state
						m_model_type = DIFF_ANALYSIS; 

						std::stringstream ss;
                        ss << "Send UploadCurrModelMsg (91) (DDS) to Geo Comp LAS Service (COMMIT): "
							<< m_upload_model_to_cloud_msg.MsgCount();
						m_event_queue.push(ss.str());

						m_event_queue.push("Model_Upload_State exit");
						InternalEvent(MODEL_REFERENCE_STATE);
					}
					else
					{
						m_event_queue.push("Model_Upload_State error");
						InternalEvent(FINALIZATION_STATE);
					}

					break;

				case DIFF_ANALYSIS:

					// Compose DDS message
					m_upload_model_to_cloud_msg.MsgId(92);
					m_upload_model_to_cloud_msg.MsgCount(++m_upload_diff_model_to_cloud_msg_cnt);
					m_upload_model_to_cloud_msg.MissionId(m_mission_plan_msg.MissionId());
					m_upload_model_to_cloud_msg.GeoPath(m_mission_plan_msg.GeoPathDiffModel().value());
					m_upload_model_to_cloud_msg.CloudUrl(m_mission_plan_msg.CloudUrlDiffModel().value());

					// Send DDS message
					if (m_dds_comm.Write<DoubleUrlMsg>("UploadDiffModelMsg", m_upload_model_to_cloud_msg))
					{
						std::stringstream ss;
                        ss << "Send UploadDiffModelMsg (92) (DDS) to Geo Comp LAS Service (COMMIT): "
							<< m_upload_model_to_cloud_msg.MsgCount();
						m_event_queue.push(ss.str());

						m_event_queue.push("Model_Upload_State exit");
						InternalEvent(MISSION_END_STATE);
					}
					else
					{
						m_event_queue.push("Model_Upload_State error");
						InternalEvent(FINALIZATION_STATE);
					}

					break;

				default:

					m_event_queue.push("Model_Upload_State error");
					InternalEvent(FINALIZATION_STATE);

					break;
			}

		default:
			break;
	}
}

// AirDiff sequence
//  - Receives user input to run differences analysis
//  - Sends RequestRefModelMsg (14) (DDS) to Geo Comp LAS Service (COMMIT)
//  - Transitions to Model_Generation_State
STATE_DEFINE(Manager, Model_Reference_State, NoEventData)
{
	m_event_queue.push("Model_Reference_State entry");

	// Wait for a UI command to compose and send RequestRefModelMsg
	m_diff_analysis_queue.pop();

	bool valid_param_flag = true;

	m_event_queue.push("Receive Start Differences Analysis command from UI console");

	if (m_mission_plan_msg.GeoPathDiffModel().value().empty())
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Geo path difference model is empty");
	}

	if (m_mission_plan_msg.CloudUrlRefModel().value().empty())
	{
		valid_param_flag = false;
		m_event_queue.push("ERROR: Cloud URL reference model is empty");
	}

	if (valid_param_flag == true)
	{
		// Compose DDS message
		m_request_ref_model_msg.MsgId(14);
		m_request_ref_model_msg.MsgCount(++m_request_ref_model_msg_cnt);
		m_request_ref_model_msg.MissionId(m_mission_plan_msg.MissionId());
		m_request_ref_model_msg.GeoPath(m_mission_plan_msg.GeoPathDiffModel().value());
		m_request_ref_model_msg.CloudUrl(m_mission_plan_msg.CloudUrlRefModel().value());

		// Send DDS message
		if (m_dds_comm.Write<DoubleUrlMsg>("RequestRefModelMsg", m_request_ref_model_msg))
		{
			std::stringstream ss;
            ss << "Send RequestRefModelMsg (14) (DDS) to Geo Comp LAS Service (COMMIT): "
				<< m_request_ref_model_msg.MsgCount();
			m_event_queue.push(ss.str());

			m_event_queue.push("Model_Reference_State exit");
			InternalEvent(MODEL_GENERATION_STATE);
		}
		else
		{
			m_event_queue.push("Model_Reference_State error");
			InternalEvent(FINALIZATION_STATE);
		}
	}
	else
	{
		m_event_queue.push("Model_Reference_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// AirBuild/AirDiff sequences
// - Receives EndMissionMsg (15) (DDS) from Geo Comp Mission Broadcaster (COMMIT)
// - Transitions to the INITIALIZATION_STATE for a new cycle
STATE_DEFINE(Manager, Mission_End_State, NoEventData)
{
	m_event_queue.push("Mission_End_State entry");

	m_mission_end_queue.pop();

	m_event_queue.push("Mission_End_State exit");
	InternalEvent(INITIALIZATION_STATE);
}

// This states stops the execution of the Manager
STATE_DEFINE(Manager, Finalization_State, NoEventData)
{
	m_event_queue.push("Finalization_State entry");

	stringstream ss;
    ss << "Thank you for using Michael's Geo Computer Manager";
	m_event_queue.push(ss.str());
	m_event_queue.push(m_sentinel);
	m_platform_location_queue.push(m_sentinel);
	
    // std::this_thread::sleep_for(std::chrono::seconds(1));

	m_event_thread.join();
	m_platform_location_thread.join();

	exit(0);	// throw std::exception();
}


// CALLBACK FUNCTIONS
// Note: The invocation of a callback function occurs at some point during program execution cycle. 
// Depending on the nature of the message, the effects of function invocation are either observed and dealt with 
// in a specific predefined state or as soon as the message arrives

// Receives MissionPlanMsg (1) (DDS) from Geo Comp Mission Broadcaster (COMMIT)
void Manager::MissionPlanMsgCb(std::vector<MissionPlanMsg> updated_data, std::vector<MissionPlanMsg> deleted_data)
{
	// Check to see whether a message that has arrived can be processed
	if (GetCurrentState() == MISSION_PLAN_STATE) 
	{
		MissionPlanMsg mission_plan_msg;

		for (auto& item : updated_data)
		{
			mission_plan_msg = item;
		}

		for (auto& item : deleted_data)
		{
			mission_plan_msg = item;
		}

		std::stringstream ss;
        ss << "Receive MissionPlanMsg (1) (DDS) from Geo Comp Mission Broadcaster (COMMIT): "
			<< mission_plan_msg.MsgCount();

		m_event_queue.push(ss.str());
		m_mission_plan_queue.push(mission_plan_msg);
	}	
}

// Receives DroneScanRouteMsg (3) (DDS) from Geo Comp Flight Plan Service (Elta)
void Manager::DroneScanRouteMsgCb(std::vector<DroneScanRouteMsg> updated_data, std::vector<DroneScanRouteMsg> deleted_data)
{
	if (GetCurrentState() == DRONE_SCAN_ROUTE_STATE)
	{
		DroneScanRouteMsg drone_scan_route_msg;

		for (auto& item : updated_data)
		{
			drone_scan_route_msg = item;
		}

		std::stringstream ss;
        ss << "Receive DroneScanRouteMsg (3) (DDS) from Geo Comp Flight Plan Service (Elta): "
			<< drone_scan_route_msg.MsgCount();

		m_event_queue.push(ss.str());
		m_drone_scan_route_queue.push(drone_scan_route_msg);
	}
}

// Receives PlatformLocationMsg (4) (DDS) from Geo Comp JPEG Generator (TES)
void Manager::PlatformLocationMsgCb(std::vector<PlatformLocationMsg> updated_data, std::vector<PlatformLocationMsg> deleted_data)
{
	// MJ TODO: Confirm with Hai that PlatformLocationMsg can arrive only during this state
	if ((GetCurrentState() == START_JPEG_GENERATION_STATE) || (GetCurrentState() == STOP_JPEG_GENERATION_STATE))
	{
		for (auto& item : updated_data)
		{
			m_platform_location_msg = item;
		}

		std::stringstream ss;
		ss << "Receive PlatformLocationMsg (4) (DDS) from Geo Comp JPEG Generator (TES): "
			<< m_platform_location_msg.MsgCount();
		m_event_queue.push(ss.str());

		std::stringstream coordinates;
		coordinates << m_platform_location_msg.PlatformLocation().Lat() << "\t"
			<< m_platform_location_msg.PlatformLocation().Lon() << "\t"
			<< m_platform_location_msg.PlatformLocation().Alt();

		m_platform_location_queue.push(coordinates.str());
	}
}

// Receives ReportJpegGenerationLivenessMsg (6) (DDS) from Geo Comp JPEG Generator (TES)
void Manager::ReportJpegGenerationLivenessMsgCb(std::vector<ReportJpegGenerationLivenessMsg> updated_data, 
	std::vector<ReportJpegGenerationLivenessMsg> deleted_data)
{
	// MJ TODO: Confirm with Hai that ReportJpegGenerationLivenessMsg can arrive only during this state
	if (GetCurrentState() == STOP_JPEG_GENERATION_STATE)
	{
		for (auto& item : updated_data)
		{
			m_report_jpeg_generation_liveness_msg = item;
		}

		m_jpeg_generation_liveness_msg_cnt++;

		// if ((m_report_jpeg_generation_liveness_msg.MsgCount() % 600) == 0) // 600 = once a minute
	//	if ((m_jpeg_generation_liveness_msg_cnt % 600) == 0) // 600 = once a minute
	//	{
		std::stringstream ss;
		ss << "Receive ReportJpegGenerationLivenessMsg (6) (DDS) from Geo Comp JPEG Generator (TES): "
			<< m_report_jpeg_generation_liveness_msg.MsgCount();
		m_event_queue.push(ss.str());
		//	}
	}
}

// Geo Comp Manager receives EndMissionMsg (15) (DDS) from Geo Comp Mission Broadcaster (COMMIT)
void Manager::EndMissionMsgCb(std::vector<BaseMsg> updated_data, std::vector<BaseMsg> deleted_data)
{
	if (GetCurrentState() == MISSION_END_STATE)
	{
		for (auto& item : updated_data)
		{
			m_mission_end_msg = item;
		}

		std::stringstream ss;
        ss << "Receive EndMissionMsg (15) (DDS) from Geo Comp Mission Broadcaster (COMMIT): "
			<< m_mission_end_msg.MsgCount();

		m_event_queue.push(ss.str());
		m_mission_end_queue.push(true);
	}
}

// Geo Comp Manager receives UserInputMsg (?) (DDS) from UserInput Service (Elta)
void Manager::UserInputMsgCb(std::vector<BaseMsg> updated_data, std::vector<BaseMsg> deleted_data)
{
	if ((GetCurrentState() == START_JPEG_GENERATION_STATE) ||
		(GetCurrentState() == STOP_JPEG_GENERATION_STATE) ||
		(GetCurrentState() == MODEL_REFERENCE_STATE))
	{
		for (auto& item : updated_data)
		{
			m_user_input_msg = item;
		}

		m_ui_cmd_cnt++;

		if (m_user_input_msg.MissionId() == 1)
		{
			m_start_jpeg_generation_queue.push(true);
		}
		else if (m_user_input_msg.MissionId() == 2)
		{
			m_stop_jpeg_generation_queue.push(true);
		}
		else if (m_user_input_msg.MissionId() == 3)
		{
			m_diff_analysis_queue.push(true);
		}
		else if (m_user_input_msg.MissionId() == 4)
		{
			std::stringstream ss;
			ss << "Total number of UI commands: " << m_ui_cmd_cnt;
			m_event_queue.push(ss.str());

			Stop();
		}
		else
		{
			// nothing
		}
	}
}