// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file defines TCP client that sends and receives messages to/from TCP server

#include "tcp_client.h"

TCP_Client::TCP_Client() : 
	m_init_flag(false),
	m_server_ip(""), 
	m_server_port(0), 
	m_client_socket(INVALID_SOCKET),
	m_client_msg_buff("\0"),
	m_server_msg_buff("\0")
{ 
	// Create new logger file for logging all events
	stringstream tcp_client_log_dir_path;
    tcp_client_log_dir_path << "/home/user/WP/Linux/GeoComp/logs/tcp_client_log_" + m_event_logger.Get_Timestamp_File() + ".txt";
    m_event_logger.Start(tcp_client_log_dir_path.str(), "TCP Client event logger is started");
}

TCP_Client::TCP_Client(std::string server_ip, int server_port) :
	m_init_flag(false),
	m_server_ip(server_ip),
	m_server_port(server_port),
	m_client_socket(INVALID_SOCKET),
	m_client_msg_buff("\0"),
	m_server_msg_buff("\0")
{ 
	// Create new logger file for logging all events
	stringstream tcp_client_log_dir_path;
    tcp_client_log_dir_path << "/home/user/WP/Linux/GeoComp/logs/tcp_client_log_" + m_event_logger.Get_Timestamp_File() + ".txt";
    m_event_logger.Start(tcp_client_log_dir_path.str(), "TCP Client event logger is started");
}

TCP_Client::~TCP_Client()
{
	Close();
}

void TCP_Client::Set_Server_IP(std::string server_ip)
{
	m_server_ip.assign(server_ip);
}

void TCP_Client::Set_Server_Port(unsigned short server_port)
{
	m_server_port = server_port;
}

bool TCP_Client::Init(void)
{
    //WSAData data;
    //WORD version = MAKEWORD(2, 2);
	stringstream ss;

	// Start WinSock
    //if (WSAStartup(version, &data) != 0)
    //{
    //	ss << "TCP CLIENT: WSAStartup() failed: " << WSAGetLastError();
    //	m_event_logger.Print(ss.str());
    //}
    //else
    //{
		// Create client sending socket
		m_client_socket = socket(AF_INET, SOCK_STREAM, 0);

		// Check to see whether socket creation succeeded
		if (m_client_socket == INVALID_SOCKET)
		{
            ss << "TCP CLIENT: socket() failed!"; // << WSAGetLastError();
			m_event_logger.Print(ss.str());
		}
		else
		{
			// Initialize m_server_info structure with server IP address and port number information
			memset((char*)&m_server_info, 0, sizeof(m_server_info));
			m_server_info.sin_family = AF_INET;							// Address format is IPv4
			m_server_info.sin_port = htons((u_short)m_server_port);
			
			// Convert IPv4 and IPv6 internet network address from text presentation into numeric binary form
			// Validate network address
			if (inet_pton(AF_INET, m_server_ip.c_str(), &m_server_info.sin_addr) <= 0)
			{
                ss << "TCP CLIENT: inet_pton() failed!"; // << WSAGetLastError();
				m_event_logger.Print(ss.str());
			}
			else
			{
				// Connect to a server
				int connect_sts = connect(m_client_socket, (struct sockaddr*)&m_server_info, sizeof(m_server_info));

				if (connect_sts == SOCKET_ERROR)
				{
                    ss << "TCP CLIENT: connect() failed!"; // << WSAGetLastError();
					m_event_logger.Print(ss.str());
				}
				else
				{
					m_init_flag = true;
				}
			}	
		}
    //}

	return m_init_flag;
}

bool TCP_Client::IsInit(void)
{
	return m_init_flag;
}

// The main processing loop
bool TCP_Client::Send(std::string msg)
{
	stringstream ss;
	bool ret_val = true;	// true = success; false = failure

	if (m_client_socket == INVALID_SOCKET)
	{
		return false;
	}

	// ssize_t write(int fd, const void *buf, size_t count);
	// ssize_t send(int sockfd, const void *buf, size_t len, int flags);
	// sendto(m_client_socket, m_client_msg_buff, strlen(m_client_msg_buff), 0, (sockaddr*)&m_server_info, sizeof(m_server_info));

    char msg_to_send[MSG_BUFF_LEN];
    memset(msg_to_send, 0, MSG_BUFF_LEN);
    memcpy(msg_to_send, msg.c_str(), msg.size());

    int num_of_tx_bytes = send(m_client_socket, msg_to_send, (msg.size() + 1), 0);
	//int num_of_tx_bytes = send(m_client_socket, msg.c_str(), (int)msg.size(), 0);
	
	if (num_of_tx_bytes == SOCKET_ERROR)
	{
        ss << "TCP CLIENT: send() failed!"; // << WSAGetLastError();
		m_event_logger.Print(ss.str());
		ret_val = false;
	}
	else
	{
        ss << "TCP CLIENT: Message has been sent";
		m_event_logger.Print(ss.str());
	}

	return ret_val;
}

int TCP_Client::Receive(std::string& rx_msg)
{
	stringstream ss;

	// int bytes_received = read(m_client_socket, m_server_msg_buff, MSG_BUFF_LEN);
	// If no error occurs, recv returns the number of bytes received and the buffer pointed to by the buf parameter 
	// will contain this data received. If the connection has been gracefully closed, the return value is zero.
    int num_of_rx_bytes = recv(m_client_socket, m_server_msg_buff, MSG_BUFF_LEN, 0);

	if (num_of_rx_bytes < 0)
	{
        ss << "TCP CLIENT: recv() failed!"; // << WSAGetLastError();
		m_event_logger.Print(ss.str());
	}

	if (num_of_rx_bytes > 0)
	{
        rx_msg.clear();
        rx_msg.assign(m_server_msg_buff, num_of_rx_bytes);
	}

	return num_of_rx_bytes;
}

void TCP_Client::Close(void)
{
	m_init_flag = false;

    if (close(m_client_socket) == SOCKET_ERROR)
    {
        stringstream ss;
        ss << "TCP CLIENT: closesocket() failed!";
        m_event_logger.Print(ss.str());
    }
    else
    {
        m_event_logger.Print("TCP CLIENT: Client socket closed");
    }
}
