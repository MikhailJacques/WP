// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file defines entry point of the application

#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <time.h>

#include "json.h"
#include "logger.h"
#include "dds_comm.h"
#include "dds_msgs.hpp"
#include "reader_listener.h"

using namespace std;
using namespace dds_msgs;

using namespace dds::core;
using namespace dds::domain;
using namespace dds::domain::qos;
using namespace dds::topic;
using namespace dds::pub;
using namespace DDS::Comm;

using namespace std;

int main()
{
	unsigned short ui_cmd_cnt = 0;
	Json::Value root;
	Json::Reader reader;
	ifstream config_file;
	Logger m_event_logger;
	BaseMsg user_input_msg;

	DDS::Comm::Communicator m_dds_comm;
	DDS::Comm::Init_Params m_dds_comm_init_params;

	// Create new logger file for logging events	
	stringstream ui_cmd_log_path;
    ui_cmd_log_path << "/home/user/WP/logs/ui_cmd_log_" + m_event_logger.Get_Timestamp_File() + ".txt";
	m_event_logger.Start(ui_cmd_log_path.str(), "UI Service event logger is started");

	// Open pre-defined DDS configuration file for reading DDS configuration information
	stringstream config_dds_path;
    config_dds_path << "/home/user/WP/config/config_dds.json";
	config_file.open(config_dds_path.str(), ios::in);

	// Read information from DDS configuration file in JSON format and store it in root
	bool init_flag = reader.parse(config_file, root);

	if (init_flag)
	{
		// Store read initializations parameters in the local structure
		m_dds_comm_init_params.domain_id = root["domain_id"].asInt();											// 66;
		m_dds_comm_init_params.communicator_name.assign(root["communicator_name"].asString());					// "WorldPerception";
		m_dds_comm_init_params.qos_default_library_name.assign(root["qos_default_library_name"].asString());	// "WorldPerceptionQoS";

		stringstream config_qos_path;
        config_qos_path << "/home/user/WP/config/USER_QOS_PROFILES.xml";
		m_dds_comm_init_params.qos_xml_uri.assign(config_qos_path.str());

		// Initialize DDS communicator
		init_flag = m_dds_comm.Init(m_dds_comm_init_params);
	}

	// Create DDS writer
	init_flag = ((init_flag) && (m_dds_comm.CreateWriter<BaseMsg>("UserInputMsg") != nullptr)) ? true : false;

    if (init_flag == false)
    {
        cout << "Error! Failed to start the app.\n";
    }
    else
    {
        // Read user input
        do
        {
            std::stringstream ss;
            std::string user_input;

            cout << "User input: ";
            getline(cin, user_input);

            if (user_input.compare("jpeg") == 0)
            {
                ss << "Receive start JPEG generation command from UI console";
                m_event_logger.Print(ss.str());

                user_input_msg.MsgId(1);
                user_input_msg.MsgCount(++ui_cmd_cnt);
                user_input_msg.MissionId(1);

                if (m_dds_comm.Write<BaseMsg>("UserInputMsg", user_input_msg))
                {
                    m_event_logger.Print("Send start JPEG generation command to Geo Comp Manager");
                }
            }
            else if (user_input.compare("model") == 0)
            {
                ss << "Receive start model generation command from UI console";
                m_event_logger.Print(ss.str());

                user_input_msg.MsgId(1);
                user_input_msg.MsgCount(++ui_cmd_cnt);
                user_input_msg.MissionId(2);

                if (m_dds_comm.Write<BaseMsg>("UserInputMsg", user_input_msg))
                {
                    m_event_logger.Print("Send start model generation command to Geo Comp Manager");
                }
            }
            else if (user_input.compare("diff") == 0)
            {
                ss << "Receive start differences analysis command from UI console";
                m_event_logger.Print(ss.str());

                user_input_msg.MsgId(1);
                user_input_msg.MsgCount(++ui_cmd_cnt);
                user_input_msg.MissionId(3);

                if (m_dds_comm.Write<BaseMsg>("UserInputMsg", user_input_msg))
                {
                    m_event_logger.Print("Send start differences analysis command to Geo Comp Manager");
                }
            }
            else if (user_input.compare("kill") == 0)
            {
                ss << "Receive program termination command from UI console";
                m_event_logger.Print(ss.str());

                user_input_msg.MsgId(1);
                user_input_msg.MsgCount(++ui_cmd_cnt);
                user_input_msg.MissionId(4);

                if (m_dds_comm.Write<BaseMsg>("UserInputMsg", user_input_msg))
                {
                    m_event_logger.Print("Send program termination command to Geo Comp Manager");
                }

                std::stringstream ss;
                ss << "Total number of processed UI commands: " << ui_cmd_cnt;
                m_event_logger.Print(ss.str());
                m_event_logger.Close("UI Service event logger is closed");
                break;
            }
            else
            {
                cout << "Invalid entry! Please try again.\n"
                    << "To start JPEG generation enter: jpeg\n"
                    << "To start model generation enter: model\n"
                    << "To start differences analysis enter: diff\n"
                    << "To terminate all services enter: kill" << endl;
            }
        } while (true);
    }

	exit(0);
}
