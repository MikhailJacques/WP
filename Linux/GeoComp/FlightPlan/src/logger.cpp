// AUTHOR:	    Mikhail Jacques
// PROJECT:		World Perception
// DOCUMENT:	None
// DESCRIPTION: This file defines logger that writes data to a text file

#include <mutex>
#include "logger.h"

Logger::Logger(const std::string& file_name) :
    m_file_name(file_name)
{
    // Open a new file for writing
    m_outfile.open(m_file_name.c_str(), std::ios::out);
}

void Logger::SetFileName(const std::string& file_name)
{
    m_file_name.assign(file_name);
}

void Logger::Start(const std::string& file_name, const std::string& msg)
{
    SetFileName(file_name);

    // Open a new file for writing
    m_outfile.open(m_file_name.c_str(), std::ios::out);

    std::stringstream ss;
    ss << Get_Timestamp() << ": " << msg << endl;
    m_outfile << ss.str();
    LOG(ss.str());
    m_outfile.flush();
}

void Logger::Print(const std::string& msg)
{
    std::stringstream ss;
    ss << Get_Timestamp_Millisec() << ": " << msg << endl;
    m_outfile << ss.str();
    LOG(ss.str());
    m_outfile.flush();
}

void Logger::Close(const std::string& msg)
{
    std::stringstream ss;
    ss << Get_Timestamp() << ": " << msg << endl;
    m_outfile << ss.str();
    LOG(ss.str());
    m_outfile.close();
}
