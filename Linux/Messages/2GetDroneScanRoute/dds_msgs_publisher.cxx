/*
* (c) Copyright, Real-Time Innovations, 2020.  All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging
// alternatively, to include all the standard APIs:
//  <dds/dds.hpp>
// or to include both the standard APIs and extensions:
//  <rti/rti.hpp>
//
// For more information about the headers and namespaces, see:
//    https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/api/connext_dds/api_cpp2/group__DDSNamespaceModule.html
// For information on how to use extensions, see:
//    https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/api/connext_dds/api_cpp2/group__DDSCpp2Conventions.html

#include "application.hpp"  // for command line parsing and ctrl-c
#include "dds_msgs.hpp"

void run_publisher_application(unsigned int domain_id, unsigned int sample_count)
{
    // DDS objects behave like shared pointers or value types
    // (see https://community.rti.com/best-practices/use-modern-c-types-correctly)

    // Start communicating in a domain, usually one participant per application
    dds::domain::DomainParticipant participant(domain_id);

    // Create a Topic with a name and a datatype
    dds::topic::Topic<dds_msgs::GetDroneScanRouteMsg> topic(participant, "GetDroneScanRouteMsg");

    // Create a Publisher
    dds::pub::Publisher publisher(participant);

    // Create a DataWriter with default QoS
    //dds::pub::DataWriter<dds_msgs::GetDroneScanRouteMsg> writer(publisher, topic);
    dds::core::QosProvider m_qos_provider = dds::core::QosProvider::Default();
    dds::pub::DataWriter<dds_msgs::GetDroneScanRouteMsg> writer(publisher, topic, m_qos_provider.datawriter_qos("WorldPerceptionQoS::GetDroneScanRouteMsg"));

    dds_msgs::GetDroneScanRouteMsg data;

    // Compose DDS message
    data.MsgId(2);
    data.MsgCount(1);
    data.MissionId(150);
    data.ScanType(dds_msgs::EnumScan::Rectangular);

    ::dds::core::array< dds_msgs::GeoPoint, 3L> waypoints;
    waypoints[0] = dds_msgs::GeoPoint(32.634203, 35.046665, 100);
    waypoints[1] = dds_msgs::GeoPoint(32.635200, 35.046665, 200);
    waypoints[2] = dds_msgs::GeoPoint(32.635200, 35.046700, 300);

    for (int ii = 0; ii < data.ScanArea().size(); ii++)
        data.ScanArea().push_back(waypoints[ii]);

    data.ScanAreaGroundAvgAlt(100);
    data.FlightAltAboveGroundAvgAlt(200);
    data.TakeoffAltAboveSeaLevel(300);
    data.FlightSpeed(20);
    data.CameraHorizontalFOV(90);
    data.CameraVerticalFOV(90);
    data.CameraHorizontalResolution(700);
    data.CameraVerticalResolution(800);
    data.OverlapInFlightDirection(50);
    data.OverlapInLateralDirection(60);
    data.GimbalPitchAngle(1000);
    data.SquareCenter(dds_msgs::GeoPoint(32, 35, 400));
    data.SquareSide(100);

    for (unsigned int samples_written = 0; !application::shutdown_requested && samples_written < sample_count; samples_written++) 
    {
        // Modify the data to be written here
        data.MsgCount(samples_written);
        writer.write(data);
        std::cout << "Writing GetDroneScanRouteMsg, count " << samples_written << std::endl;

        // Send once every second
        rti::util::sleep(dds::core::Duration(2));
    }
}

int main(int argc, char *argv[])
{
    using namespace application;

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);

    arguments.domain_id = 66;
    arguments.sample_count = 20;

    try {
        run_publisher_application(arguments.domain_id, arguments.sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
        << std::endl;
        return EXIT_FAILURE;
    }

    // Releases the memory used by the participant factory.  Optional at
    // application exit
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
