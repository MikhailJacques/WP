// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file declares TCP server that accepts messages

#pragma once

#ifdef _WIN32 // _MSC_VER
#include <WS2tcpip.h>				// Header file for Winsock functions
#define _WINSOCKAPI_				// Stops windows.h including winsock
#include "windows.h"
#pragma comment(lib, "ws2_32.lib")	// Winsock library file
#else // Linux
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SOCKET int
#define INVALID_SOCKET (-1)
#define SOCKET_ERROR (-1)
#endif

#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <sstream>
#include "json.h"
#include "msg_buff.h"

using namespace std;

#define PORT 5678
#define MSG_BUFF_LEN (1024)

// Forward declaration of class
class TCP_Server;

// Callback to data received
typedef void(*RxMsgHandler)(TCP_Server *tcp_server_ptr, SOCKET client_socket, std::string msg);

// Algorithm:
// Initialize winsock
// Create a listening socket
// Bind the IP address and port to a socket
// Tell Winsock the socket is for listening
// Wait for a connection
// Accept connection
// Close listening socket
// Receive loop
//		Send message
// Close the socket

class TCP_Server
{
public:

    TCP_Server(std::string server_ip, int server_port, RxMsgHandler rx_msg_handler);
	~TCP_Server();
	bool Init(void);						// Initializes winsockand creates a listening socket
	void Run(void);							// Receives messages on the connected client socket	
    int Send(SOCKET client_socket, std::string msg); // Sends a message to the connected client socket

private:

	// Waits for a connection on a listening socket and returns a client socket
	SOCKET WaitForConnection(SOCKET listening_socket);
	SOCKET CreateListeningSocket(void);		// Creates a listening socket
	void GetClientInfo(void);				// Retrieves client's info

	void Cleanup(void);						// Cleans up after using the service
	void Print_Msg(string msg);				// Prints a status message

	std::string	m_server_ip;				// Server IP address
	int	m_server_port;						// Server listening port
	sockaddr_in m_client_info;				// Client information
    RxMsgHandler m_rx_msg_handler;			// Received message event handler
};
