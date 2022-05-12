// AUTHOR:		Mikhail Jacques
// PROJECT:		TCP Server
// DOCUMENT:	
// DESCRIPTION: This file defines the entry point of the application

#include "tcp_server.h"

string GetUserInput(void);
void Rx_Msg_Handler(TCP_Server* server, SOCKET client_socket, string msg);

int main()
{
	TCP_Server server("127.0.0.1", PORT, Rx_Msg_Handler);

	if (server.Init())
	{
		server.Run();
	}

	return 0;
}

void Rx_Msg_Handler(TCP_Server* server, SOCKET client_socket, string msg)
{
	Json::Value root;
	Json::Reader reader;
	
	// Read information from message in JSON format and store it in root
	bool parse_flag = reader.parse(msg, root);

	cout << msg << endl;

	if (parse_flag == true)
	{
		//unsigned short msg_id = root["MsgId"].asUInt();
		//unsigned short msg_cnt = root["MsgCount"].asUInt();
		unsigned short mission_id = root["MissionId"].asUInt();
		//unsigned short model_type = root["ModelType"].asUInt();
		//string geo_path_jpeg_files = root["GeoPathJpegFiles"].asString();
		//string geo_path_curr_model = root["GeoPathCurrModel"].asString();
		//string geo_path_ref_model = root["GeoPathRefModel"].asString();
		//string geo_path_diff_model = root["GeoPathDiffModel"].asString();

		//cout << "TCP SERVER: Message received: \n";
		//cout << "MsgId: " << msg_id
		//	<< ", MsgCount: " << msg_cnt
		//	<< ", MissionId: " << mission_id
		//	<< ", ModelType: " << model_type
		//	<< ", GeoPathJpegFiles: " << geo_path_jpeg_files
		//	<< ", GeoPathCurrModel: " << geo_path_curr_model
		//	<< ", GeoPathRefModel: " << geo_path_ref_model
		//	<< ", GeoPathDiffModel: " << geo_path_diff_model
		//	<< endl;

		string status;
		unsigned int tx_msg_cnt = 0;

		do {

			status = GetUserInput();

			if (status.compare("kill") == 0)
			{
				cout << "TCP SERVER: Thank you for using Michael's TCP server: ";
				exit(0);
			}

			// Compose ReportModelGenerationMsg (8) in JSON format
			Json::Value root;
			root["MsgId"] = 8;
			root["MsgCount"] = ++tx_msg_cnt;
			root["MissionId"] = mission_id;
			root["Status"] = status;
			root["ErrorCode"] = 1;

			Json::FastWriter fast_writer;
			std::string ReportModelGenerationMsg = fast_writer.write(root);

			int num_of_tx_bytes = server->Send(client_socket, ReportModelGenerationMsg);

		} while (status.compare("done") != 0);
	}
}

string GetUserInput(void)
{
	string ui_msg;

	do
	{
		cout << "TCP SERVER: Message to send: ";
		getline(cin, ui_msg);

		if ((ui_msg.compare("start") == 0) || (ui_msg.compare("progress") == 0) || 
			(ui_msg.compare("done") == 0) || (ui_msg.compare("kill") == 0))
		{
			break;
		}
		else
		{
			cout << "TCP SERVER: Invalid entry! Please try again.\n"
				<< "Valid entries are: start, progress, done, kill" << endl;
		}
	} while (true);

	return ui_msg;
}

std::string ConvertToString(char* a, int size)
{
	int i;
	std::string s = "";

	for (i = 0; i < size; i++)
	{
		s = s + a[i];
	}

	return s;
}