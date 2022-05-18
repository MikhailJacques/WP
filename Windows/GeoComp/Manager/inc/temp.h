// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file contains code samples. 
//				It is auxiliary in nature and will excluded from the release version.

#pragma once

// This code might become relevant if the Stop() function is ever invoked from the main() 
// and appropriate log data is supplied to be printed in the Finalization_State 
//class LogEventData : public EventData
//{
//	public:
//
//		void SetMsg(std::string msg)
//		{
//			m_msg.assign(msg);
//		}
//
//		std::string GetMsg(void)
//		{
//			return m_msg;
//		}
//
//	private:
//		std::string m_msg;
//};

//for (int ii = 0; ii < m_mission_plan_msg.ScanArea().size(); ii++)
//	m_get_drone_scan_route_msg.ScanArea().at(ii) = m_mission_plan_msg.ScanArea().at(ii);

//copy(m_mission_plan_msg.ScanArea().begin(), m_mission_plan_msg.ScanArea().end(), m_get_drone_scan_route_msg.ScanArea().begin());
// ::rti::core::bounded_sequence<dds_msgs::GeoPoint, 100L>::iterator itr = waypoints.begin();


//std::stringstream ss;
//ss << "Message id: " << m_report_jpeg_generation_liveness_msg.MsgId()
//<< "Message cnt: " << m_report_jpeg_generation_liveness_msg.MsgCount()
//<< "Mission id: " << m_report_jpeg_generation_liveness_msg.MissionId()
//<< "Mission name: " << m_report_jpeg_generation_liveness_msg.MissionId()
//<< "Platform id: " << m_report_jpeg_generation_liveness_msg.PlatformType()
//<< "Platform id: " << m_report_jpeg_generation_liveness_msg.PlatformId()
//<< "Number of JPEG files: " << m_report_jpeg_generation_liveness_msg.NumOfJpegFiles()
//<< "Status: " << m_report_jpeg_generation_liveness_msg.Status();

//// Read user input to Start JPEG Generation
//do
//{
//	std::string user_input;
//
//	cout << "To start JPEG generation enter: startjpeg" << endl;
//	getline(cin, user_input);
//
//	if (user_input.compare("startjpeg") == 0)
//	{
//		m_event_logger.Print("Receive Start JPEG Generation command from UI console");
//		break;
//	}
//	else
//	{
//		cout << "Invalid entry" << endl;
//	}
//} while (true);

//// Read user input to Start Model Generation
//do
//{
//	std::string user_input;
//
//	cout << "To start model generation enter: generate" << endl;
//	getline(cin, user_input);
//
//	if (user_input.compare("generate") == 0)
//	{
//		m_event_logger.Print("Receive Start Model Generation command from UI console");
//		break;
//	}
//	else
//	{
//		cout << "Invalid entry" << endl;
//	}
//} while (true);

//switch (m_mission_plan_msg.MissionType())
//{
//case dds_msgs::EnumMission::AirBuild:
//	break;
//case dds_msgs::EnumMission::AirDiff:
//	break;
//case dds_msgs::EnumMission::GroundBuild:
//	break;
//case dds_msgs::EnumMission::GroundDiff:
//	break;
//default:
//	break;
//}

//m_mission_plan_msg.MsgId();
//m_mission_plan_msg.MissionId();
//m_mission_plan_msg.MissionName();
//m_mission_plan_msg.MissionType();	// dds_msgs::EnumMission
//m_mission_plan_msg.StationId();
//m_mission_plan_msg.PlatformType();	// dds_msgs::EnumPlatform::Drone
//m_mission_plan_msg.PlatformId();
//m_mission_plan_msg.ScanType();		// dds_msgs::EnumScan::Rectangular
//
////::dds::core::array< dds_msgs::GeoPoint, 3L> waypoints;
////waypoints[0] = dds_msgs::GeoPoint(32.634203, 35.046665, 470);
////waypoints[1] = dds_msgs::GeoPoint(32.635200, 35.046665, 470);
////waypoints[2] = dds_msgs::GeoPoint(32.635200, 35.046770, 470);
//
//m_mission_plan_msg.ScanArea(); // ::dds::core::array< dds_msgs::GeoPoint, 3L> waypoints;
//m_mission_plan_msg.ScanAreaGroundAvgAlt();
//m_mission_plan_msg.FlightAltAboveGroundAvgAlt();
//m_mission_plan_msg.TakeoffAltAboveSeaLevel();
//m_mission_plan_msg.FlightSpeed();
//m_mission_plan_msg.CameraHorizontalFOV();
//m_mission_plan_msg.CameraVerticalFOV();
//m_mission_plan_msg.CameraHorizontalResolution();
//m_mission_plan_msg.CameraVerticalResolution();
//m_mission_plan_msg.OverlapInFlightDirection();
//m_mission_plan_msg.OverlapInLateralDirection();
//m_mission_plan_msg.GimbalPitchAngle();
//m_mission_plan_msg.SquareCenter(dds_msgs::GeoPoint(33.5, 36.5, 300));
//m_mission_plan_msg.SquareSide(0);
//m_mission_plan_msg.GeoPathJpegFiles().value();
//m_mission_plan_msg.GeoPathCurrModel();
//m_mission_plan_msg.GeoPathRefModel().value();
//m_mission_plan_msg.GeoPathDiffModel().value();
//m_mission_plan_msg.CloudUrlCurrModel();
//m_mission_plan_msg.CloudUrlRefModel().value();
//m_mission_plan_msg.CloudUrlDiffModel().value();

// Create a separate thread to execute the blocking receive call, store the received info 
// in a member variable of class type with a new data flag, and read from it via locks.

//std::string reqJson = (std::string)"{" +
//"\"obs\": \"../../../flights/viewpoint-dji/DJI_20201112190112_0001_S.MP4\"," +
//"\"ref\": \"../../../flights/viewpoint_ply/lashabya_40m_w/ref_cropped.ply\"," +
//"\"frames\": 50," +
//"\"image-side\": 400," +
//"\"max-features\": 1200" +
//"}";
//send(sock, reqJson.c_str(), reqJson.size(), 0);
//printf("Json request sent\n");

//for (auto& item : deleted_data)
//{
//	cout << "Message id: " << item.MsgId();
//}

//#ifdef _MSC_VER
//// Windows
//#else
//// Linux
//#endif

//#ifndef _MSC_VER
//   // Linux
//#endif

//#define NULL_GUARD(_x_)  \
//    if(_x_ == NULL) return

// MJ TODO: Discuss with Sightec the purpose of this block of code
// MJ TODO: Possibly parse the message out with jasoncpp
//while (model_upload_state_flag == false)
//{
//	size_t pos = rx_msg.find('\n');
//	std::string line = rx_msg.substr(0, pos);
//	rx_msg = (pos == -1) ? "" : rx_msg.substr(pos + 1);

//	if (line.size() > 0)
//	{
//		// MJ TODO: Output status to console and possibly to log
//		// stringstream ss;
//		//ss << line;
//		//m_event_queue.push(ss.str());
//		//ss.clear(); ss.str("");

//		model_upload_state_flag = line.compare("done");
//	}
//}

//std::string msg1 = (std::string)"{" +
//	"\"obs\": \"../../../flights/viewpoint-dji/DJI_20201112190112_0001_S.MP4\"," +
//	"\"ref\": \"../../../flights/viewpoint_ply/lashabya_40m_w/ref_cropped.ply\"," +
//	"\"frames\": 50," +
//	"\"image-side\": 400," +
//	"\"max-features\": 1200" +
//	"}";

//std::stringstream ss;
//ss << "{"
//	<< "\"MsgId\": << 7 << \","
//	<< "\"MsgCount\": " << ++m_start_model_generation_msg_cnt << ","
//	<< "\"MissionId\": " << m_mission_plan_msg.MissionId() << ","
//	<< "\"ModelType\": " << m_model_type << ","
//	<< "\"GeoPathJpegFiles\": \"" << m_mission_plan_msg.GeoPathJpegFiles().value() << "\","
//	<< "\"GeoPathCurrModel\": \"" << m_mission_plan_msg.GeoPathCurrModel() << "\","
//	<< "\"GeoPathRefModel\": \"" << m_mission_plan_msg.GeoPathRefModel().value() << "\","
//	<< "\"GeoPathDiffModel\": \"" << m_mission_plan_msg.GeoPathDiffModel().value() << "\""
//	<< "}";

//cout << msg << endl;
//Json::Value root2;
//Json::Reader reader;
//bool parse_flag = reader.parse(msg, root2);
//if (parse_flag == true)
//{
//	unsigned char msg_id = root2["MsgId"].asUInt();
//	unsigned int msg_cnt = root2["MsgCount"].asUInt();
//	unsigned short mission_id = root2["MissionId"].asUInt();
//	unsigned char model_type = root2["ModelType"].asUInt();
//	std::string geo_path_jpeg_files = root2["GeoPathJpegFiles"].asString();
//	std::string geo_path_curr_model = root2["GeoPathCurrModel"].asString();
//	std::string geo_path_ref_model = root2["GeoPathRefModel"].asString();
//	std::string geo_path_diff_model = root2["GeoPathDiffModel"].asString();
//}


//            char buff[MSG_BUFF_LEN];

//            // Set message length in message header
//            unsigned short payload_len = StartModelGenerationMsg.size();
//            buff[0] = payload_len & 0xff;
//            buff[1] = (payload_len >> 8) & 0xff;

//            // Set message payload
//            memcpy(&buff[2], StartModelGenerationMsg.c_str(), payload_len);

//            std::string msg_to_server = "";

//            for (int i = 0; i < payload_len + 2; i++)
//            {
//                msg_to_server = msg_to_server + buff[i];
//            }

    //buff[payload_len + 2] = '\0';
    //std::string msg_to_server(buff);

//                char msg_len[3];
//                memset(msg_len, 0, 3);
//                strncpy(msg_len, msg_buff, 2);

//                char msg_payload[MSG_BUFF_LEN];
//                memset(msg_payload, 0, MSG_BUFF_LEN);
//                strncpy(msg_payload, &msg_buff[2], (num_of_rx_bytes - 2));

//                unsigned short len = atoi(msg_len);

//                if (len != (num_of_rx_bytes - 2))
//                {
//                    m_event_queue.push("Model_Generation_State error");
//                    m_event_queue.push("ERROR: Wrong message length!");
//                    comm_error_flag = true;
//                }
