// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file declares TCP client that sends messages

#pragma once

#ifdef _WIN32 // _MSC_VER
#include <WS2tcpip.h>				// Header file for Winsock functions
#define _WINSOCKAPI_				// Stops windows.h including winsock
#include "windows.h"
#pragma comment(lib, "ws2_32.lib")	// Winsock library file
#else // Linux
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SOCKET int
#define INVALID_SOCKET (-1)
#define SOCKET_ERROR (-1)
#endif

#include <string>
#include <sstream>
#include <iostream>
#include "logger.h"

using namespace std;

// Algorithm:
// Initialize winsock
// Create a socket
// Fill in a hint structure with server information
// Connect to a server
// Do-while loop to send and receive data
// Gracefully close down everything

const unsigned short MSG_BUFF_LEN = (1024);

class TCP_Client
{
public:

	TCP_Client();
	TCP_Client(std::string server_ip, int server_port);
	~TCP_Client();
	void Set_Server_IP(std::string server_ip);			// Sets server IP address
	void Set_Server_Port(unsigned short server_port);	// Sets server port number
    bool Init(void);                                    // Initializes socket and connects to client; returns true on success; false otherwise
	bool IsInit(void);									// Returns client initialization status
    bool Send(std::string msg);                         // Sends a message to the specified server
    int Receive(std::string& rx_msg);                   // Receives a message from the specified server
	void Close(void);									// Cleans up after using the winsock service

private:

	bool m_init_flag;						// true: client has been initialized; false otherwise
	std::string m_server_ip;				// Server IP address
	unsigned short m_server_port;			// Server port
	sockaddr_in m_server_info;				// Server metadata
	SOCKET m_client_socket;					// Client socket descriptor
    char m_client_msg_buff[MSG_BUFF_LEN];	// Buffer to store outgoing message to the server
    char m_server_msg_buff[MSG_BUFF_LEN];	// Buffer to store incoming message from the server
	Logger m_event_logger;					// Logger object that writes event occurences to a text log file
};