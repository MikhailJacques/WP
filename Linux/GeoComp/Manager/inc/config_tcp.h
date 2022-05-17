// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file defines a structure that stores network configuration information

#pragma once

#include <mutex>
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

class CONFIG_TCP
{
public:

	CONFIG_TCP(std::string server_ip_sightec, unsigned short server_port_sightec, 
		std::string server_ip_third_eye, unsigned short server_port_third_eye) :
		m_server_ip_sightec(server_ip_sightec),
		m_server_ip_third_eye(server_ip_third_eye),
        m_server_port_sightec(server_port_sightec),
		m_server_port_third_eye(server_port_third_eye),
		m_valid_flag(true) { }

	void Init(std::string server_ip_sightec, unsigned short server_port_sightec,
		std::string server_ip_third_eye, unsigned short server_port_third_eye)
	{
		m_server_ip_sightec.assign(server_ip_sightec);
		m_server_ip_third_eye.assign(server_ip_third_eye);

		m_server_port_sightec = server_port_sightec;
		m_server_port_third_eye = server_port_third_eye;

		m_valid_flag = true;
	}

	CONFIG_TCP()
	{
		Reset();
	}

	// Copy constructor
	CONFIG_TCP(const CONFIG_TCP& CONFIG_TCP) :
		m_server_ip_sightec(CONFIG_TCP.m_server_ip_sightec),
		m_server_ip_third_eye(CONFIG_TCP.m_server_ip_third_eye),
		m_server_port_sightec(CONFIG_TCP.m_server_port_sightec),
		m_server_port_third_eye(CONFIG_TCP.m_server_port_third_eye),
		m_valid_flag(CONFIG_TCP.m_valid_flag) { }

	// Overloaded assignment operator
	CONFIG_TCP& operator=(const CONFIG_TCP& rhs)
	{
		if (this == &rhs)
			return *this;

		m_server_ip_sightec.assign(rhs.m_server_ip_sightec);
		m_server_ip_third_eye.assign(rhs.m_server_ip_third_eye);

		m_server_port_sightec = rhs.m_server_port_sightec;
		m_server_port_third_eye = rhs.m_server_port_third_eye;

		m_valid_flag = rhs.m_valid_flag;

		return *this;
	}

	~CONFIG_TCP() {}

	void Reset(void)
	{
		m_server_ip_sightec.clear();
		m_server_ip_third_eye.clear();

		m_server_port_sightec = 0;
		m_server_port_third_eye = 0;

		m_valid_flag = false;
	}

	std::string m_server_ip_sightec;
	std::string m_server_ip_third_eye;

	unsigned short m_server_port_sightec;
	unsigned short m_server_port_third_eye;

	bool m_valid_flag;	// true - object contains fresh valid data; false otherwise	
};
