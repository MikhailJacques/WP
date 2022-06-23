// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	Drone Scan Route Specifications (22-06-21)
// DESCRIPTION: This module implements comb flight path algorithm

#include <cmath>
#include <array>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <time.h>

#include "queue.h"
#include "logger.h"
#include "earth_distance.h"

// Algorithm: 
// Given 3 points
// Calculate the length of the first long leg (great circle geo distance between the first two points (RSAL/LLL))
// Calculate bearing of the first long leg (great circle geo line between the first two waypoints)
// Calculate bearing of the first short leg
// Calculate bearing of the opposite long leg
// Calculate perpendicular geo distance from the geo line between the first two points and the third point (minimum width of the RSA)
// Perform intermediary calculations based on configuration and user-defined data
// Calculate the first short leg
// Calculate the second long leg
// Calculate the second short leg
// Calculate the third long leg
// Calculate the third short leg
// Continue in this fashion until the end

int main()
{
    // Configuration parameters 
    double camera_horizontal_fov = 42.0;            // (CHFOV) Degrees, [0.5, 180.0], default 42
    double camera_vertical_fov = 32.0;              // (CVFOV) Degrees, [0.5, 180.0], default 32
    double camera_horizontal_resolution = 4208.0;   // (CHR) Pixels,  [50, 20,000], default 4208
    double camera_vertical_resolution = 3120.0;     // (CVR) Pixels,  [50, 20,000], default 3120
    unsigned short overlap_between_adjacent_frames_in_flight_direction = 80;    // (OBAF) %, [10, 90] default 80%
    unsigned short overlap_between_opposite_frames_in_lateral_direction = 70;   // (OBOF) %, [10, 90] default 70%
    unsigned short camera_pitch_angle = -70;        // (CPA) Degrees, [-20, -85], default -70
    unsigned short drone_turning_time = 3;          // (DTT) Seconds [0, 30], default 3

    // User input parameters 
    //GeoCoord coord[3];                            // (RSA) Decimal degrees, meters [-90.0, 90.0], [-180.0, 180.0], [-432, 1,500]
    unsigned short ground_avg_alt_level = 100;      // (GAAL) Meters, [-432, 1,500], default 100
    unsigned short flight_alt_above_ground_avg_level = 150; // (FAAGAL) Meters, [5, 1,500], default 150
    unsigned short take_off_alt_above_sea_level = 100;      // (TAASL) Meters, [-432, 1,500], default 100
    unsigned short flight_speed = 10;               // (FS) Meters per second, [0, 150], default 10
    unsigned short local_square_dimension = 300;    // (LSD) Meters, [50, 2,000], default 300

    // Omer's set 1
    // GeoCoord coord[3] = { {32.2912458, 34.8764098}, {32.2912458, 34.8748112}, {32.2933091, 34.8759162} };

    // Omer's set 2
    // GeoCoord coord[3] = { {32.2912322, 34.8749989}, {32.2911641, 34.8776811}, {32.2926515, 34.8776919} };

    // Omer's set 3
    // GeoCoord coord[3] = { {32.2931005, 34.8761684}, {32.2916992, 34.8775470}, {32.2910009, 34.8763937} };

    // Michael's set 4
    // GeoCoord coord[3] = { {22.560206299999997, 88.41253929999999}, {22.620867969497795, 88.36928063300775}, {22.71558662052875, 88.29580956367181} };

    // Michael's set 5
    GeoCoord coord[3] = { {3.227511, 101.724318}, {3.222895, 101.719751}, {3.224972, 101.722932} };

     // Create new logger file for logging all events	
    Logger m_event_logger;	// Logger object that writes event occurences to a text log file
    stringstream log_path;
    log_path << SolutionDir << "logs\\event_log_" + m_event_logger.Get_Timestamp_File() + ".txt";
    m_event_logger.Start(log_path.str(), "Event logger is started");

    // Calculations --------------------

    // Calculate rectangular scan area length (RSAL/LLL), which is great circle geo distance between WP1 and WP2
    double rsal_1 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_1(coord);
    double rsal_2 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_2(coord);
    double rsal_3 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_3(coord);
    double rsal_4 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_4(coord);
    double rsal_5 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_5(coord[0].lat, coord[0].lon, coord[1].lat, coord[1].lon);
    double rectangular_scan_area_length = rsal_4;
    double long_leg_length = rectangular_scan_area_length;

    std::stringstream ss;
    ss << "Rectangular scan area length (RSAL/LLL) (meters): " << rectangular_scan_area_length;
    m_event_logger.Print(ss.str());
    ss.str(""); ss.clear();

    // Calculate bearing of the great circle geo line between WP1 and WP2
    double bearing_1 = Earth_Distance::EarthBearingBetweenTwoGeoCoord_1(coord);
    double bearing_2 = Earth_Distance::EarthBearingBetweenTwoGeoCoord_2(coord);
    double bearing_3 = Earth_Distance::EarthBearingBetweenTwoGeoCoord_3(coord[0].lat, coord[0].lon, coord[1].lat, coord[1].lon);
    double long_leg_bearing = bearing_2;

    ss << "Bearing of the first long leg (degrees): " << long_leg_bearing;
    m_event_logger.Print(ss.str());
    ss.str(""); ss.clear();

    double integral_part, fractional_part, short_leg_bearing, opposite_long_leg_bearing;

    // Calculate bearing of the first short leg (degrees)
    fractional_part = modf(long_leg_bearing + 90.0, &integral_part);
    short_leg_bearing = ((int)integral_part + 360) % 360 + fractional_part;

    ss << "Bearing of the first short leg (degrees) : " << short_leg_bearing;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate bearing of the opposite long leg (degrees)
    fractional_part = modf(long_leg_bearing + 180.0, &integral_part);
    opposite_long_leg_bearing = ((int)integral_part + 360) % 360 + fractional_part;

    ss << "Bearing of the second long leg (degrees) : " << opposite_long_leg_bearing;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate rectangular scan area minimum width (shortest geo distance between a line formed by WP1 and WP2 and point3)
    double min_width_1 = Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_1(coord);
    double min_width_2 = Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_3(coord);
    double min_width_3 = Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_3(coord);
    double rectangular_scan_area_minimum_width = min_width_3;

    ss << "Rectangular scan area minimum width (meters): " << rectangular_scan_area_minimum_width;
    m_event_logger.Print(ss.str());
    ss.str(""); ss.clear();

    // MJ TODO: Confirm with Hai
    // Calculate flight altitude above sea level
    double flight_alt_above_sea_level = ground_avg_alt_level + flight_alt_above_ground_avg_level - take_off_alt_above_sea_level;

    ss << "Flight altitude above sea level (meters): " << flight_alt_above_sea_level;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate ground horizontal projection of camera's horizontal field of view
    double ground_horizontal_projection_of_camera_horizontal_fov = camera_horizontal_fov * DEG2miniRAD * flight_alt_above_ground_avg_level / 1000.0;

    ss << "Ground horizontal projection of camera's horizontal field of view: " << ground_horizontal_projection_of_camera_horizontal_fov;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate ground vertical projection of camera's vertical field of view
    double ground_vertical_projection_of_camera_vertical_fov = camera_vertical_fov * DEG2miniRAD * flight_alt_above_ground_avg_level / 1000.0;

    ss << "Ground vertical projection of camera's vertical field of view: " << ground_vertical_projection_of_camera_vertical_fov;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate model ground resolution in the vertical camera orientation
    double model_ground_resolution = ground_vertical_projection_of_camera_vertical_fov / camera_vertical_resolution * 100.0;

    ss << "Model ground resolution in the vertical camera orientation: " << model_ground_resolution;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate distance between the centers of the adjacent frames in flight direction
    double distance_between_adjacent_frames = ground_vertical_projection_of_camera_vertical_fov *
        (100 - overlap_between_adjacent_frames_in_flight_direction) / 100.0;

    ss << "Distance between the centers of the adjacent frames in flight direction (meters): " << distance_between_adjacent_frames;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate maximum time period between taking adjacent frames in flight direction
    double max_time_period_between_taking_adjacent_frames_in_flight_direction = distance_between_adjacent_frames / flight_speed;

    ss << "Maximum time period between taking adjacent frames in flight direction (seconds): " << max_time_period_between_taking_adjacent_frames_in_flight_direction;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate short leg length based on the overlap required between adjacent ground horizontal projections 
    // of the camera horizontal field of view orientation
    double short_leg_length = ground_horizontal_projection_of_camera_horizontal_fov * 
        (100 - overlap_between_opposite_frames_in_lateral_direction) / 100.0;

    ss << "Short leg length (meters): " << short_leg_length;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    
    // Scan route flight duration calculations --------------------

    // Calculate the number of long legs necessary to cover the entire scan area
    double num_of_long_legs = ceil(rectangular_scan_area_minimum_width / short_leg_length) + 1;

    ss << "Number of long legs necessary to cover the entire scan area : " << num_of_long_legs;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate the number of short legs necessary to cover the entire scan area
    double num_of_short_legs = num_of_long_legs - 1;

    ss << "Number of short legs necessary to cover the entire scan area : " << num_of_short_legs;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate the actual rectangular scan area width
    double rectangular_scan_area_width = num_of_short_legs * short_leg_length;

    ss << "Actual rectangular scan area width (meters): " << rectangular_scan_area_width;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate long leg flight time (seconds)
    double long_leg_flight_time = rectangular_scan_area_length / flight_speed;

    ss << "Long leg flight time (seconds): " << long_leg_flight_time;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate long legs total flight time (seconds)
    double long_legs_total_flight_time = long_leg_flight_time * num_of_long_legs;

    ss << "Long legs total flight time (seconds): " << long_legs_total_flight_time;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate short leg flight time (seconds)
    double short_leg_flight_time = short_leg_length / flight_speed + (drone_turning_time * 2);

    ss << "Short leg flight time (seconds): " << short_leg_flight_time;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate short legs total flight time (seconds)
    double short_legs_total_flight_time = short_leg_flight_time * num_of_short_legs;

    ss << "Short legs total flight time (seconds): " << short_legs_total_flight_time;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate scan route total flight time (seconds)
    double scan_route_total_flight_time = (long_legs_total_flight_time + short_legs_total_flight_time) / 60.0;

    ss << "Scan route total flight time (seconds) : " << scan_route_total_flight_time;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate the number of frames per long leg
    double number_of_frames_per_long_leg = ceil(rectangular_scan_area_length / distance_between_adjacent_frames);

    ss << "Number of frames per long leg : " << number_of_frames_per_long_leg;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    // Calculate total number of frames
    double total_number_of_frames = number_of_frames_per_long_leg * num_of_long_legs;

    ss << "Total number of frames : " << total_number_of_frames;
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();


    // Waypoints calculations --------------------

    vector<GeoCoord> waypoints;

    waypoints.push_back(coord[0]);
    waypoints.push_back(coord[1]);

    // Calculate geo coordinates of the third waypoint (wp3)
    GeoCoord wp = Earth_Distance::FindGeoCoordAtDistanceFrom_2(coord[1], short_leg_bearing, short_leg_length);

    waypoints.push_back(wp);

    int long_leg_cnt = 1, short_leg_cnt = 1;

    for (int ii = 3; ii < (num_of_long_legs * 2); ii++)
    {
        if ((ii % 2) == 0)
        {
            short_leg_cnt++;

            wp = Earth_Distance::FindGeoCoordAtDistanceFrom_2(wp, short_leg_bearing, short_leg_length);
        }
        else
        {
            long_leg_cnt++;

            if ((long_leg_cnt % 2) == 0)
            {
                wp = Earth_Distance::FindGeoCoordAtDistanceFrom_2(wp, opposite_long_leg_bearing, long_leg_length);
            }
            else
            {
                wp = Earth_Distance::FindGeoCoordAtDistanceFrom_2(wp, long_leg_bearing, long_leg_length);
            }
        }

        waypoints.push_back(wp);
    }

    ss << "Waypoints: ";
    m_event_logger.Print(ss.str()); ss.str(""); ss.clear();

    for (int ii = 0; ii < waypoints.size(); ii++)
    {
        //ss << std::setprecision(7) << fixed << showpoint << "WP" << (ii+1) <<
        //    ":\t (" << waypoints[ii].lat << ", " << waypoints[ii].lon << ")";

        //ss << std::setprecision(7) << fixed << showpoint << "WP" << (ii + 1) <<
        //    ", " << waypoints[ii].lat << ", " << waypoints[ii].lon;

        ss << std::setprecision(7) << fixed << showpoint << "WP" << (ii + 1) <<
            "\t" << waypoints[ii].lat << "\t" << waypoints[ii].lon;

        m_event_logger.Print(ss.str()); ss.str(""); ss.clear();
    }
}