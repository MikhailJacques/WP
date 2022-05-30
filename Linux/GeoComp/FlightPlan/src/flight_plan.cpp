// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file defines a state machine where clients can induce changes via invocation of external events.
//				The FlightPlan essentially performs the actual business logic work.

#include <mutex>
#include "flight_plan.h"

using namespace std;
using namespace dds_msgs;

// Constructor reads configuration information, initializes DDS communicator
FlightPlan::FlightPlan(void) :
	StateMachine(NUM_OF_STATES, INITIALIZATION_STATE),
	m_constructor_success_flag(false),
	m_drone_scan_route_msg_cnt(0)
{
	Json::Value root;
	Json::Reader reader;
	ifstream config_file;

	// Create new logger file for logging events	
	stringstream flight_plan_log_path;
    flight_plan_log_path << "/home/user/WP/Linux/GeoComp/logs/flight_plan_log_" + m_event_logger.Get_Timestamp_File() + ".txt";
	m_event_logger.Start(flight_plan_log_path.str(), "Flight Plan Service event logger is started");

	// Open pre-defined DDS configuration file for reading DDS configuration information
	stringstream config_dds_path;
    config_dds_path << "/home/user/WP/Linux/GeoComp/config/config_dds.json";
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
        config_qos_path << "/home/user/WP/Linux/GeoComp/config/USER_QOS_PROFILES.xml";
        m_dds_comm_init_params.qos_xml_uri.assign(config_qos_path.str());

		// Initialize DDS communicator
		init_flag = m_dds_comm.Init(m_dds_comm_init_params);
	}

	// Create DDS readers
	if (init_flag)
	{
		m_dds_comm.RegisterOnData<GetDroneScanRouteMsg>("GetDroneScanRouteMsg",
			std::bind(&FlightPlan::GetDroneScanRouteMsgCb, this, std::placeholders::_1, std::placeholders::_2));

		m_dds_comm.RegisterOnData<BaseMsg>("UserInputMsg", std::bind(&FlightPlan::UserInputMsgCb, this, 
			std::placeholders::_1, std::placeholders::_2));
	}

	// Create DDS writer
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<DroneScanRouteMsg>("DroneScanRouteMsg") != nullptr)) ? true : false;

	if (init_flag == true)
	{
		m_constructor_success_flag = true;
		m_event_logger.Print("Constructor success");
	}
	else
	{
		m_constructor_success_flag = false;
		m_event_logger.Print("Constructor error");

		CounterData data;
		data.ui_cmd_cnt = 0;
		Stop(&data);
	}
}

// This function starts the execution of the FlightPlan (enters the state machine)
void FlightPlan::Start(void)
{
	/// BEGIN_TRANSITION_MAP starts the map. 
	/// Each TRANSITION_MAP_ENTRY that follows indicates what the state machine should do based upon the current state. 
	/// The number of entries in each transition map table must match the number of state functions exactly. 
	/// The location of each entry matches the order of state functions defined within the state map. 
	/// Thus, the first entry within the Init() function indicates an EVENT_IGNORED as shown below.
		BEGIN_TRANSITION_MAP								/// Current State:
			TRANSITION_MAP_ENTRY(INITIALIZATION_STATE)		/// INITIALIZATION_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)				/// GET_DRONE_SCAN_ROUTE_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)				/// CALCULATE_DRONE_SCAN_ROUTE_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)				/// SEND_DRONE_SCAN_ROUTE_STATE
			TRANSITION_MAP_ENTRY(CANNOT_HAPPEN)				/// FINALIZATION_STATE
		END_TRANSITION_MAP(NULL)

	/// END_TRANSITION_MAP terminates the map. 
	/// The argument to this end macro is the event data, if any. 
	/// Start() has no event data so the argument is NULL.
}

// This function stops the execution of the FlightPlan 
void FlightPlan::Stop(CounterData *data)
{
	BEGIN_TRANSITION_MAP							/// Current State:
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)	/// INITIALIZATION_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)	/// GET_DRONE_SCAN_ROUTE_STATE - If a Stop event occurs while the current state is 'any state', then transition to state Finalization_State.
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)	/// CALCULATE_DRONE_SCAN_ROUTE_STATE
		TRANSITION_MAP_ENTRY(FINALIZATION_STATE)	/// SEND_DRONE_SCAN_ROUTE_STATE
		TRANSITION_MAP_ENTRY(EVENT_IGNORED)			/// FINALIZATION_STATE
	END_TRANSITION_MAP(data)
}

STATE_DEFINE(FlightPlan, Initialization_State, NoEventData)
{
	m_event_logger.Print("Initialization_State entry");

	if (m_constructor_success_flag == true)
	{
		m_event_logger.Print("Initialization_State exit");
		InternalEvent(GET_DRONE_SCAN_ROUTE_STATE);
	}
	else
	{
		m_event_logger.Print("Initialization_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// This state receives GetDroneScanRouteMsg (2) (DDS) from Geo Comp Manager (Elta)
STATE_DEFINE(FlightPlan, Get_Drone_Scan_Route_State, NoEventData)
{
	m_event_logger.Print("Get_Drone_Scan_Route_State entry");
	m_get_drone_scan_route_queue.pop();
	m_event_logger.Print("Get_Drone_Scan_Route_State exit");
	InternalEvent(CALCULATE_DRONE_SCAN_ROUTE_STATE);
}

// This state calculates drone scan route
STATE_DEFINE(FlightPlan, Calculate_Drone_Scan_Route_State, NoEventData)
{
	m_event_logger.Print("Calculate_Drone_Scan_Route_State entry");

	// MJ TODO: Implement the following algorithm
	//	1. Extract information from m_get_drone_scan_route_msg
	//	2. Calculate drone scan route based on the retrieved information
	//  3. Fill out the m_drone_scan_route_msg

	//int ii = 0;
	//const unsigned int denom = 100000;      // 
	//
	//double latitude = m_get_drone_scan_route_msg.ScanArea().at(0).Lat();		// [-90.0, 90.0] degrees        
	//double longitude = m_get_drone_scan_route_msg.ScanArea().at(0).Lon();		// [-180.0, 180.0] degrees   
	//double altitude = m_get_drone_scan_route_msg.ScanArea().at(0).Alt();		// [-432.0, 1500.0] meters 
	//double radius = m_get_drone_scan_route_msg.ScanArea().at(1).Lat();			// [20.0, 200.0] meters
	//unsigned short num_of_points = m_get_drone_scan_route_msg.ScanArea().at(1).Lon();	// [40, 360] meters, must be a multiple of 4

	//unsigned short num_of_degrees_per_section = 360 / num_of_points;
	//
	//radius /= denom;	// Normalize radius

	//// MJ TODO: Advise Hai that in light of the new demand to develop and implement circular-navigation algorithm
	//// 100L needs to be updated to 360L and that necessitates change of ICD
	//// std::vector<dds_msgs::GeoPoint> flight_path;          // Stores navigation points around circular flight path
	//::rti::core::bounded_sequence<dds_msgs::GeoPoint, 100L> flight_path;

	//// First quadrant
	//for (; ii < 90; ii += num_of_degrees_per_section)
	//{
	//	dds_msgs::GeoPoint geo_point((latitude + radius * cos(RAD2DEG(ii))), (longitude + radius * sin(RAD2DEG(ii))), altitude);
	//	flight_path.push_back(geo_point);
	//}

	//// Second quadrant
	//for (; ii < 180; ii += num_of_degrees_per_section)
	//{
	//	dds_msgs::GeoPoint geo_point((latitude - radius * cos(RAD2DEG(180.0 - ii))), (longitude + radius * sin(RAD2DEG(180.0 - ii))), altitude);
	//	flight_path.push_back(geo_point);
	//}

	//// Third quadrant
	//for (; ii < 270; ii += num_of_degrees_per_section)
	//{
	//	dds_msgs::GeoPoint geo_point((latitude - radius * cos(RAD2DEG(ii - 180.0))), (longitude - radius * sin(RAD2DEG(ii - 180.0))), altitude);
	//	flight_path.push_back(geo_point);
	//}

	//// Fourth quadrant
	//for (; ii < 360; ii += num_of_degrees_per_section)
	//{
	//	dds_msgs::GeoPoint geo_point((latitude + radius * cos(RAD2DEG(360.0 - ii))), (longitude - radius * sin(RAD2DEG(360.0 - ii))), altitude);
	//	flight_path.push_back(geo_point);
	//}

	dds_msgs::GeoPoint flight_path[8] =
	{
		{32.634203, 35.046665, 470},
		{32.635200, 35.046665, 470},
		{32.635200, 35.046700, 470},
		{32.634200, 35.046700, 470},
		{32.634200, 35.046735, 470},
		{32.635200, 35.046735, 470},
		{32.635200, 35.046700, 470},
		{32.634200, 35.046700, 470}
	};

	::rti::core::bounded_sequence<dds_msgs::GeoPoint, 100L> geo_points;

	for (int jj = 0; jj < 8; jj++)
	{
		geo_points.push_back(flight_path[jj]);
	}

	//for (int ii = 0; ii < flight_path.size(); ii++)
	//{
	//	dds_msgs::GeoPoint point = flight_path[ii];
	//	waypoints.push_back(flight_path[ii]);
	//}

	//for (auto rit = std::rbegin(flight_path); rit != std::rend(flight_path); ++rit) 
	//{
	//	dds_msgs::GeoPoint point = *rit;
	//	waypoints.push_back(*rit);
	//}

	// Compose message
	m_drone_scan_route_msg.MsgId(3);
	m_drone_scan_route_msg.MsgCount(++m_drone_scan_route_msg_cnt);		// 200
	m_drone_scan_route_msg.MissionId(150);								// m_get_drone_scan_route_msg.MissionId()
	m_drone_scan_route_msg.Waypoints(geo_points);

	// MJ TODO: Discuss with Hai the absense of need in these parameters in light of the new circular-path navigation algorithm
	m_drone_scan_route_msg.ScanAreaLength(1000);
	m_drone_scan_route_msg.ScanAreaWidth(105);
	m_drone_scan_route_msg.ModelGroundResolution(8);
	m_drone_scan_route_msg.TimePeriodBetweenFrames(20);
	m_drone_scan_route_msg.ShortLegLength(35);
	m_drone_scan_route_msg.NumOfFramesPerLongLeg(60);
	m_drone_scan_route_msg.TotalNumOfFrames(240);

	bool calculate_success_flag = true;

	if (calculate_success_flag == true)
	{
		m_event_logger.Print("Calculate_Drone_Scan_Route_State exit");
		InternalEvent(SEND_DRONE_SCAN_ROUTE_STATE);
	}
	else
	{
		m_event_logger.Print("Calculate_Drone_Scan_Route_State error");
		InternalEvent(FINALIZATION_STATE);
	}
}

// This state sends DroneScanRouteMsg (3) (DDS) to Geo Comp JPEG Generator (TES) and Geo Comp Mission Broadcaster (COMMIT)
STATE_DEFINE(FlightPlan, Send_Drone_Scan_Route_State, NoEventData)
{
	m_event_logger.Print("Send_Drone_Scan_Route_State entry");

    m_event_logger.Print("Send DroneScanRouteMsg (3) (DDS) to Geo Comp JPEG Generator (TES)\n and Geo Comp Mission Broadcaster (COMMIT)");
	if (m_dds_comm.Write<DroneScanRouteMsg>("DroneScanRouteMsg", m_drone_scan_route_msg))
	{
		m_event_logger.Print("Send_Drone_Scan_Route_State exit");
		InternalEvent(INITIALIZATION_STATE);
	}
	else
	{
		m_event_logger.Print("Send_Drone_Scan_Route_State error");
		InternalEvent(FINALIZATION_STATE);
	}	
}

// This states stops the execution of the FlightPlan
STATE_DEFINE(FlightPlan, Finalization_State, CounterData)
{
	m_event_logger.Print("Finalization_State entry");

	std::stringstream ss;
	ss << "Total number of UI commands: " << data->ui_cmd_cnt;
	m_event_logger.Print(ss.str());
	m_event_logger.Print("Finalization_State exit");
	m_event_logger.Close("Flight Plan Service event logger is closed");

	exit(0);	// throw std::exception();
}

// Geo Comp Manager receives DroneScanRouteMsg (3) (DDS) from Geo Comp Flight Plan Service (Elta)
void FlightPlan::GetDroneScanRouteMsgCb(std::vector<GetDroneScanRouteMsg> updated_data, std::vector<GetDroneScanRouteMsg> deleted_data)
{
	if (GetCurrentState() == GET_DRONE_SCAN_ROUTE_STATE)
	{
		for (auto& item : updated_data)
		{
			m_get_drone_scan_route_msg = item;
		}

		std::stringstream ss;
        ss << "Receive GetDroneScanRouteMsg (2) (DDS) from Geo Comp Manager(Elta): "
			<< m_get_drone_scan_route_msg.MsgCount();
		m_event_logger.Print(ss.str());
		m_get_drone_scan_route_queue.push(true);
	}
}

// Geo Comp Manager receives UserInputMsg (?) (DDS) from UserInput Service (Elta)
void FlightPlan::UserInputMsgCb(std::vector<BaseMsg> updated_data, std::vector<BaseMsg> deleted_data)
{
	static unsigned short ui_cmd_cnt = 0;

	for (auto& item : updated_data)
	{
		m_user_input_msg = item;
	}

	ui_cmd_cnt++;

	if (m_user_input_msg.MissionId() == 4)
	{
		CounterData data;
		data.ui_cmd_cnt = ui_cmd_cnt;
		Stop(&data);
	}
	else
	{
		// nothing
	}
}
