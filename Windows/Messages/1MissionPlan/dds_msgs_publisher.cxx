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
    dds::topic::Topic<dds_msgs::MissionPlanMsg> topic(participant, "MissionPlanMsg");

    // Create a Publisher
    dds::pub::Publisher publisher(participant);

    // Create a DataWriter with default QoS
    // dds::pub::DataWriter<dds_msgs::MissionPlanMsg> writer(publisher, topic);
    dds::core::QosProvider m_qos_provider = dds::core::QosProvider::Default();
    dds::pub::DataWriter<dds_msgs::MissionPlanMsg> writer(publisher, topic, m_qos_provider.datawriter_qos("WorldPerceptionQoS::MissionPlanMsg"));

    dds_msgs::MissionPlanMsg data;

    data.MsgId(1);
    data.MissionId(150);
    data.MissionName("Elyakim_1_Diff");
    //data.MissionType(dds_msgs::EnumMission::AirBuild);
    data.MissionType(dds_msgs::EnumMission::AirDiff);
    //data.MissionType(dds_msgs::EnumMission::GroundBuild);
    //data.MissionType(dds_msgs::EnumMission::GroundDiff);
    data.StationId(5);
    data.PlatformType(dds_msgs::EnumPlatform::Drone);
    data.PlatformId(25);
    data.ScanType(dds_msgs::EnumScan::Rectangular);

    ::dds::core::array< dds_msgs::GeoPoint, 3L> waypoints;

    // Comb-style flight pattern
    //waypoints[0] = dds_msgs::GeoPoint(32.634203, 35.046665, 470);
    //waypoints[1] = dds_msgs::GeoPoint(32.635200, 35.046665, 470);
    //waypoints[2] = dds_msgs::GeoPoint(32.635200, 35.046770, 470);

    // Circular flight pattern
    waypoints[0] = dds_msgs::GeoPoint(32.6363504, 35.0475073, 470);
    waypoints[1] = dds_msgs::GeoPoint(100.0, 60, 0);
    waypoints[2] = dds_msgs::GeoPoint(0, 0, 0);

    data.ScanArea(waypoints);
    data.ScanAreaGroundAvgAlt(170);
    data.FlightAltAboveGroundAvgAlt(300);
    data.TakeoffAltAboveSeaLevel(190);
    data.FlightSpeed(10);
    data.CameraHorizontalFOV(42);
    data.CameraVerticalFOV(32);
    data.CameraHorizontalResolution(4208);
    data.CameraVerticalResolution(3120);
    data.OverlapInFlightDirection(80);
    data.OverlapInLateralDirection(70);
    data.GimbalPitchAngle(-70);
    data.SquareCenter(dds_msgs::GeoPoint(33.5, 36.5, 300));
    data.SquareSide(0);

    std::string geo_path_jpeg_files("/home/amit/jpeg_test");
    data.GeoPathJpegFiles(geo_path_jpeg_files);

    std::string geo_path_curr_model("/home/bob");
    data.GeoPathCurrModel(geo_path_curr_model);

    std::string geo_path_ref_model("/home/bob");
    data.GeoPathRefModel(geo_path_ref_model);

    std::string geo_path_diff_model("/home/bob");
    data.GeoPathDiffModel(geo_path_diff_model);

    std::string cloud_url_curr_model("/home/bob");
    data.CloudUrlCurrModel(cloud_url_curr_model);

    std::string cloud_url_ref_model("/home/bob");
    data.CloudUrlRefModel(cloud_url_ref_model);

    std::string cloud_url_diff_model("/home/bob");
    data.CloudUrlDiffModel(cloud_url_diff_model);

    for (unsigned int samples_written = 0; !application::shutdown_requested && samples_written < sample_count; samples_written++)
    {
        // Modify the data to be written here
        data.MsgCount(samples_written);
        writer.write(data);
        std::cout << "Writing MissionPlanMsg, count " << samples_written << std::endl;

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
    arguments.sample_count = 30;

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
