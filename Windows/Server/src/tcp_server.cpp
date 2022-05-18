// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file defines TCP server that accepts messages

#include "tcp_server.h"

TCP_Server::TCP_Server(std::string server_ip, int server_port, RxMsgHandler rx_msg_handler) :
	m_server_ip(server_ip),
	m_server_port(server_port),
    m_rx_msg_handler(rx_msg_handler)
{ 
	m_client_info = {};

	if (m_rx_msg_handler == NULL)
	{
		stringstream ss;
		ss << "SERVER ERROR: Constructor(): m_rx_msg_handler is NULL";
		Print_Msg(ss.str());
	}
}

TCP_Server::~TCP_Server()
{
	Cleanup();
}

// This function initializes winsock ans creates a listening socket
bool TCP_Server::Init(void)
{
	// The WSADATA structure contains information about the Windows sockets implementation
	WSADATA wsa_data;	
	WORD ver = MAKEWORD(2, 2);
	stringstream ss;

	int wsa_init_sts = WSAStartup(ver, &wsa_data);

	if (wsa_init_sts != 0)
	{
		ss << "SERVER ERROR: Init() failed: " << wsa_init_sts;
		Print_Msg(ss.str());
	}

	return (wsa_init_sts == 0);
}

// This function creates a listening socket
SOCKET TCP_Server::CreateListeningSocket(void)
{
	SOCKET listening_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (listening_socket != INVALID_SOCKET)
	{
		// Create structure to bind the IP address and port number to the listening socket
		// In order for a server to communicate on a network, it must bind the socket to a network address.
		// Need to assemble the required data for connection in sockaddr structure.
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(m_server_port);	// host to network short
		inet_pton(AF_INET, m_server_ip.c_str(), &hint.sin_addr);

		// Bind the IP address and port to the listening socket
		int bind_sts = bind(listening_socket, (sockaddr*)&hint, sizeof(hint));

		if (bind_sts != SOCKET_ERROR)
		{
			// Tell Winsock the socket is for listening
			int listen_sts = listen(listening_socket, SOMAXCONN);

			if (listen_sts == SOCKET_ERROR)
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}

	return listening_socket;
}

// This function waits for a connection on a listening socket and 
// upon establishing the connection creates a connected client socket
SOCKET TCP_Server::WaitForConnection(SOCKET listening_socket)
{
    socklen_t client_size = sizeof(m_client_info);

	// The accept function permits an incoming connection attempt on a socket.
	SOCKET client_socket = accept(listening_socket, (sockaddr*)&m_client_info, &client_size);

	if (client_socket == INVALID_SOCKET)
	{
		stringstream ss;
		ss << "SERVER ERROR: accept() failed: " << WSAGetLastError();
		Print_Msg(ss.str());

		return -1;
	}
	else
	{
		// Once a client is connected, close the listening socket so that no other clients can connect on it
		closesocket(listening_socket);
	}

	return client_socket;
}

void TCP_Server::GetClientInfo(void)
{
	// Code from bare-bones echo server 
	char host[NI_MAXHOST];				// Client's remote name
	char client_port[NI_MAXHOST];		// Client's port

	memset(host, 0, NI_MAXHOST);
	memset(client_port, 0, NI_MAXHOST);

	// Get client's host name (DNS lookup)
	// The getnameinfo function is used to translate the contents of a socket address structure to a node name and/or a service name. 
	if (getnameinfo((sockaddr*)&m_client_info, sizeof(m_client_info), host, NI_MAXHOST, client_port, NI_MAXHOST, 0) == 0)
	{
        cout << "TCP SERVER: Client " << host << " connected on port " << client_port << endl;
	}
	else
	{
        inet_ntop(AF_INET, &m_client_info.sin_addr, host, NI_MAXHOST);
        cout << "TCP SERVER: Client " << host << " connected on port" << ntohs(m_client_info.sin_port) << endl;
	}
}

// This function receives data from a client on the specified client socket
void TCP_Server::Run(void)
{
	char rx_buff[MSG_BUFF_LEN];

	while (true)
	{
		SOCKET listening_socket = CreateListeningSocket();

		if (listening_socket == INVALID_SOCKET)
		{
			Print_Msg("SERVER ERROR: CreateListeningSocket() failed!");
			break;
		}
		else
		{
			stringstream ss;
			ss << "TCP SERVER: Listening on port: " << PORT;
			Print_Msg(ss.str());
		}

		SOCKET client_socket = WaitForConnection(listening_socket);

		if (client_socket != INVALID_SOCKET)
		{
			closesocket(listening_socket);

			int num_of_rx_bytes = 0;

			GetClientInfo();

			do {

				memset(rx_buff, 0, MSG_BUFF_LEN);

				// Wait to receive data from the client
				num_of_rx_bytes = recv(client_socket, rx_buff, MSG_BUFF_LEN, 0);

				if (num_of_rx_bytes == SOCKET_ERROR)
				{
					Print_Msg("SERVER ERROR: recv() failed!");
				}
				else if (num_of_rx_bytes == 0)
				{
					Print_Msg("TCP SERVER: Client disconnected");
				}
				else if (num_of_rx_bytes > 0)
				{
					if (m_rx_msg_handler != NULL)
					{
                        string rx_msg = std::string(rx_buff, 0, num_of_rx_bytes);

                        m_rx_msg_handler(this, client_socket, rx_msg);
					}
				}
			} while (num_of_rx_bytes > 0);

			closesocket(client_socket);
		}
	}
}

// This function sends data on a connected client socket
int TCP_Server::Send(SOCKET client_socket, std::string msg)
{
	int num_of_tx_bytes = send(client_socket, msg.c_str(), (int)msg.size() + 1, 0);

	if (num_of_tx_bytes == SOCKET_ERROR)
	{
		stringstream ss;
		ss << "SERVER ERROR: send() failed: " << WSAGetLastError();
		Print_Msg(ss.str());
	}

	return num_of_tx_bytes;
}

// This function shuts the server down
void TCP_Server::Cleanup(void)
{
	Print_Msg("TCP SERVER: Shutting down");
	WSACleanup();
}

// This function prints out a status message
void TCP_Server::Print_Msg(string msg)
{
	std::cout << msg << std::endl;
}