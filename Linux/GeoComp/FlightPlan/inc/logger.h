// AUTHOR:	    Mikhail Jacques
// PROJECT:		World Perception
// DOCUMENT:	None
// DESCRIPTION: This file declares logger that writes data to a text file

#pragma once

#include <mutex>
#include <string>
#include <chrono>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#if QT_DEBUG || DEBUG || _DEBUG
#define LOG(x) std::cout << x
#else
#define LOG(x) std::cout << x
#endif

#define NULL_GUARD(_x_)  \
    if(_x_ == NULL) return

class Logger
{
public:

    Logger() {};
    Logger(const std::string& file_name);
    ~Logger() {};

    void SetFileName(const std::string& file_name);
    void Start(const std::string& file_name, const std::string& msg);
    void Print(const std::string& msg);
    void Close(const std::string& msg);

    // Gets a precise timestamp as a string
    std::string Get_Timestamp_File()
    {
        std::time_t t = std::time(nullptr);
        stringstream ss;
        ss << put_time(std::localtime(&t), "%F %T"); // ISO 8601 without timezone information

        auto timestamp = ss.str();
        replace(timestamp.begin(), timestamp.end(), ':', '-');
        replace(timestamp.begin(), timestamp.end(), '-', '_');
        replace(timestamp.begin(), timestamp.end(), ' ', '_');

        return timestamp;
    }

private:

    // Gets a precise timestamp (milliseconds resolution) as a string
    std::string Get_Timestamp_Millisec()
    {
        std::time_t t = std::time(nullptr);
        std::localtime(&t);
        chrono::system_clock::time_point now = chrono::system_clock::now();
        chrono::milliseconds now_ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;
        stringstream timestamp;
        timestamp << put_time(std::localtime(&t), "%Y-%m-%d %T") << '.' << setfill('0') << setw(3) << now_ms.count();

        return timestamp.str();
    }

    // Gets a timestamp as a string
    std::string Get_Timestamp()
    {
        std::time_t t = std::time(nullptr);
        std::localtime(&t);

        stringstream timestamp;
        timestamp << put_time(std::localtime(&t), "%Y-%m-%d %T");

        return timestamp.str();
    }

    std::string m_file_name;
    std::ofstream m_outfile;
};
