// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file implements comb flight path algorithm

#include "earth_distance.h"

// Algorithm: Given 3 points
// Calculate great circle line geo distance between the first two points (RSAL/LLL)
// Calculate bearing of the great circle geo line between the first two points
// Calculate perpendicular geo distance from the geo line between the first two points and the third point
// Perform intermediary calculations
// Calculate the first short leg
// Calculate the second long leg
// Calculate the second short leg
// Calculate the third long leg
// Calculate the third shorg leg
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
    GeoCoord coord[3];                              // (RSA) Decimal degrees, meters [-90.0, 90.0], [-180.0, 180.0], [-432, 1,500]
    unsigned short ground_avg_alt_level = 100;      // (GAAL) Meters, [-432, 1,500], default 100
    unsigned short flight_alt_above_ground_avg_level = 150; // (FAAGAL) Meters, [5, 1,500], default 150
    unsigned short take_off_alt_above_sea_level = 100;      // (TAASL) Meters, [-432, 1,500], default 100
    unsigned short flight_speed = 10;               // (FS) Meters per second, [0, 150], default 10
    unsigned short local_square_dimension = 300;    // (LSD) Meters, [50, 2,000], default 300

    //coord[0].lat = 22.560206299999997;
    //coord[0].lon = 88.41253929999999;
    //coord[1].lat = 22.620867969497795;
    //coord[1].lon = 88.36928063300775;
    //coord[2].lat = 22.71558662052875;
    //coord[2].lon = 88.29580956367181;

    //coord[0].lat = 53.32055555555556;
    //coord[0].lon = -1.7297222222222221;
    //coord[1].lat = 53.31861111111111;
    //coord[1].lon = -1.6997222222222223;

    //coord[0].lat = 3.227511;
    //coord[0].lon = 101.724318;
    //coord[1].lat = 3.222895;
    //coord[1].lon = 101.719751;
    //coord[2].lat = 3.224972;
    //coord[2].lon = 101.722932;

    //// Omer's set 1
    //coord[0].lat = 32.2912458;
    //coord[0].lon = 34.8764098;
    //coord[1].lat = 32.2912458;
    //coord[1].lon = 34.8748112;
    //coord[2].lat = 32.2933091;
    //coord[2].lon = 34.8759162;

    //// Omer's set 2
    //coord[0].lat = 32.2912322;
    //coord[0].lon = 34.8749989;
    //coord[1].lat = 32.2911641;
    //coord[1].lon = 34.8776811;
    //coord[2].lat = 32.2926515;
    //coord[2].lon = 34.8776919;

    //// Omer's set 3
    coord[0].lat = 32.2931005;
    coord[0].lon = 34.8761684;
    coord[1].lat = 32.2916992;
    coord[1].lon = 34.8775470;
    coord[2].lat = 32.2910009;
    coord[2].lon = 34.8763937;

    // Omer's set 3
    // The distance between [32.2931005, 34.8761684] and [32.2916992, 34.8775470] is: 0.2025 km or 0.1258 mile
    //GeoCoord 
    //    wp1 = { DEG2RAD(32.2931005), DEG2RAD(34.8761684) },
    //    wp2 = { DEG2RAD(32.2916992), DEG2RAD(34.8775470) },
    //    point3 = { DEG2RAD(32.2910009), DEG2RAD(34.8763937) };

    // Calculations

    // Calculate bearing between WP1 and WP2
    double bearing_1 = Earth_Distance::EarthBearingBetweenTwoGeoCoord_1(coord);
    double bearing_2 = Earth_Distance::EarthBearingBetweenTwoGeoCoord_2(coord);
    double bearing_3 = Earth_Distance::EarthBearingBetweenTwoGeoCoord_3(coord[0].lat, coord[0].lon, coord[1].lat, coord[1].lon);
    double bearing = bearing_2;

    // Calculate rectangular scan area length (RSAL) (geo distance between WP1 and WP2)
    double rsal_1 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_1(coord);
    double rsal_2 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_2(coord);
    double rsal_3 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_3(coord);
    double rsal_4 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_4(coord);
    double rsal_5 = Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_5(coord[0].lat, coord[0].lon, coord[1].lat, coord[1].lon);
    double rectangular_scan_area_length = rsal_4;

    // Calculate rectangular scan area minimum width (shortest geo distance between a line (WP1, WP2) and a point3)
    double min_width_1 = Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_1(coord);
    double min_width_2 = Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_3(coord);
    double min_width_3 = Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_3(coord);
    double rectangular_scan_area_minimum_width = min_width_3;


    // Calculate flight altitude above sea level
    double flight_alt_above_sea_level = flight_alt_above_ground_avg_level - take_off_alt_above_sea_level;

    // Calculate ground horizontal projection of camera's horizontal field of view
    double ground_horizontal_projection_of_camera_horizontal_fov = camera_horizontal_fov * DEG2miniRAD * flight_alt_above_ground_avg_level / 1000.0;

    // Calculate ground vertical projection of camera's vertical field of view
    double ground_vertical_projection_of_camera_vertical_fov = camera_vertical_fov * DEG2miniRAD * flight_alt_above_ground_avg_level / 1000.0;

    // Calculate model ground resolution in the vertical camera orientation
    double model_ground_resolution = ground_vertical_projection_of_camera_vertical_fov / camera_vertical_resolution * 100.0;

    // Calculate distance between the centers of the adjacent frames in flight direction
    double distance_between_adjacent_frames = ground_vertical_projection_of_camera_vertical_fov *
        (1 - overlap_between_adjacent_frames_in_flight_direction);

    // Calculate maximum time period between taking adjacent frames in flight direction
    double max_time_period_between_taking_adjacent_frames_in_flight_direction = distance_between_adjacent_frames / flight_speed;

    // Calculate short leg length based on the overlap required between adjacent ground horizontal projections 
    // of the camera horizontal field of view orientation
    double short_leg_length = ground_horizontal_projection_of_camera_horizontal_fov * 
        (1 - overlap_between_opposite_frames_in_lateral_direction);

    // Scan route flight duration calculations

    // Calculate the number of long legs necessary to cover the entire scan area
    double num_of_long_legs = ceil(rectangular_scan_area_minimum_width / short_leg_length) + 1;

    double num_of_short_legs = num_of_long_legs - 1;

    // Calculate the actual rectangular scan area width
    double rectangular_scan_area_width = num_of_short_legs * short_leg_length;

    // Calculate long leg flight time
    double long_leg_flight_time = rectangular_scan_area_length / flight_speed;

    // Calculate long legs total flight time
    double long_legs_total_flight_time = long_leg_flight_time * num_of_long_legs;

    // Calculate short leg flight time
    double short_leg_flight_time = short_leg_length / flight_speed + (drone_turning_time * 2);

    // Calculate short legs total flight time
    double short_legs_total_flight_time = short_leg_flight_time * num_of_short_legs;

    // Calculate scan route total flight time (in minutes)
    double scan_route_total_flight_time = (long_legs_total_flight_time + short_legs_total_flight_time) / 60.0;

    // Calculate the number of frames per long leg
    double number_of_frames_per_long_leg = ceil(rectangular_scan_area_length / distance_between_adjacent_frames);

    // Calculate total number of frames
    double total_number_of_frames = number_of_frames_per_long_leg * num_of_long_legs;
}