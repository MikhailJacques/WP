// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	Drone Scan Route Specifications (22-06-21)
// DESCRIPTION: This module defines mathematical functions for calculating comb flight path algorithm

#include "earth_distance.h"

// This function calculates a location of a geo coordinate located in a certain predefined direction and 
// at a certain predefined distance from the original geo coordinate.
// Input: Start geo coordinate (decimal degrees), earth bearing (decimal degrees), distance (meters)
// Output: Destination geo coordinate location (decimal degrees)
GeoCoord Earth_Distance::FindGeoCoordAtDistanceFrom_1(GeoCoord start_coord, double bearing_deg, double distance_m)
{
    // Convert degrees to radians
    double bearing_rad = DEG2RAD(bearing_deg);
    double start_lat_cos = cos(DEG2RAD(start_coord.lat));
    double start_lat_sin = sin(DEG2RAD(start_coord.lat));

    double distance_ratio_sin = sin(distance_m / EARTH_RADIUS_M);
    double distance_ratio_cos = cos(distance_m / EARTH_RADIUS_M);

    double end_lat_rad = asin((start_lat_sin * distance_ratio_cos) + (start_lat_cos * distance_ratio_sin * cos(bearing_rad)));

    double end_lon_rad = DEG2RAD(start_coord.lon) +
        atan2((sin(bearing_rad) * distance_ratio_sin * start_lat_cos), (distance_ratio_cos - start_lat_sin * sin(end_lat_rad)));

    GeoCoord end_coord = { RAD2DEG(end_lat_rad), RAD2DEG(end_lon_rad) };

    return end_coord;
}

// This function calculates a location of a geo coordinate located in a certain predefined direction and 
// at a certain predefined distance from the original geo coordinate.
// Input: Start geo coordinate (decimal degrees), earth bearing (decimal degrees), distance (meters)
// Output: Destination geo coordinate location (decimal degrees)
GeoCoord Earth_Distance::FindGeoCoordAtDistanceFrom_2(GeoCoord start_coord, double bearing_deg, double distance_m)
{
    // Convert degrees to radians
    double bearing_rad = DEG2RAD(bearing_deg);
    double start_lat_rad = DEG2RAD(start_coord.lat);
    double start_lon_rad = DEG2RAD(start_coord.lon);
    
    double end_lat_rad = asin(sin(start_lat_rad) * cos(distance_m / EARTH_RADIUS_M) + cos(start_lat_rad) * 
        sin(distance_m / EARTH_RADIUS_M) * cos(bearing_rad));

    double end_lon_rad = start_lon_rad + atan2(sin(bearing_rad) * sin(distance_m / EARTH_RADIUS_M) * 
        cos(start_lat_rad), cos(distance_m / EARTH_RADIUS_M) - sin(start_lat_rad) * sin(end_lat_rad));

    GeoCoord end_coord = { RAD2DEG(end_lat_rad), RAD2DEG(end_lon_rad) };

    return end_coord;
}

// This function calculates bearing between two geo coordinates.
// Input: Array of two geo coordinates (decimal degrees)
// Output: Bearing from first coordinate to the second coordinate (decimal degrees)
double Earth_Distance::EarthBearingBetweenTwoGeoCoord_1(GeoCoord coord[2])
{
    double teta1_rad = DEG2RAD(coord[0].lat);
    double teta2_rad = DEG2RAD(coord[1].lat);
    double delta1_rad = DEG2RAD(coord[1].lat - coord[0].lat);
    double delta2_rad = DEG2RAD(coord[1].lon - coord[0].lon);

    double y = sin(delta2_rad) * cos(teta2_rad);
    double x = cos(teta1_rad) * sin(teta2_rad) - sin(teta1_rad) * cos(teta2_rad) * cos(delta2_rad);

    double bearing = RAD2DEG(atan2(y, x));

    double integral_part;
    double fractional_part = modf(bearing, &integral_part);

    bearing = ((int)integral_part + 360) % 360 + fractional_part;

    return bearing;
}

// This function calculates bearing between two geo coordinates.
// Input: Array of two geo coordinates (decimal degrees)
// Output: Bearing from first coordinate to the second coordinate (decimal degrees)
double Earth_Distance::EarthBearingBetweenTwoGeoCoord_2(GeoCoord coord[2])
{
    double lat1_rad = DEG2RAD(coord[0].lat);
    double lon1_rad = DEG2RAD(coord[0].lon);
    double lat2_rad = DEG2RAD(coord[1].lat);
    double lon2_rad = DEG2RAD(coord[1].lon);

    double delta_lon = lon2_rad - lon1_rad;

    double delta_phi = log(tan(lat2_rad / 2.0 + M_PI / 4.0) / tan(lat1_rad / 2.0 + M_PI / 4.0));

    if (abs(delta_lon) > M_PI)
    {
        delta_lon = (delta_lon > 0.0) ? -(2.0 * M_PI - delta_lon) : (2.0 * M_PI + delta_lon);
    }

    double bearing = RAD2DEG(atan2(delta_lon, delta_phi));

    double integral_part;
    double fractional_part = modf(bearing, &integral_part);

    bearing = ((int)integral_part + 360) % 360 + fractional_part;

    return bearing;
}

// This function calculates bearing between two geo coordinates.
// Input: Latitudes and longitudes of two geo coordinates (decimal degrees)
// Output: Bearing from first coordinate to the second coordinate (decimal degrees)
double Earth_Distance::EarthBearingBetweenTwoGeoCoord_3(double lat1, double lon1, double lat2, double lon2)
{
    double lat1_rad = DEG2RAD(lat1);
    double lon1_rad = DEG2RAD(lon1);
    double lat2_rad = DEG2RAD(lat2);
    double lon2_rad = DEG2RAD(lon2);

    double delta_lon = lon2_rad - lon1_rad;

    double delta_phi = log(tan(lat2_rad / 2.0 + M_PI / 4.0) / tan(lat1_rad / 2.0 + M_PI / 4.0));

    if (abs(delta_lon) > M_PI)
    {
        delta_lon = (delta_lon > 0.0) ? -(2.0 * M_PI - delta_lon) : (2.0 * M_PI + delta_lon);
    }

    double bearing = RAD2DEG(atan2(delta_lon, delta_phi));

    double integral_part;
    double fractional_part = modf(bearing, &integral_part);

    bearing = ((int)integral_part + 360) % 360 + fractional_part;

    return bearing;
}

// This function calculates great-circle distance (meters) between 
// two geo coordinates over the Earth’s surface using the ‘Haversine’ formula
// Input: Array of two geo coordinates (decimal degrees)
// Output: Distance between two geo coordinates (meters)
double Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_1(GeoCoord coord[2])
{
    double lat1_rad = DEG2RAD(coord[0].lat);
    double lon1_rad = DEG2RAD(coord[0].lon);
    double lat2_rad = DEG2RAD(coord[1].lat);
    double lon2_rad = DEG2RAD(coord[1].lon);

    double u = sin((lat2_rad - lat1_rad) / 2);
    double v = sin((lon2_rad - lon1_rad) / 2);

    double distance = asin(sqrt(u * u + cos(lat1_rad) * cos(lat2_rad) * v * v)) * EARTH_RADIUS_M * 2.0;

    return distance;
}

// This function calculates great-circle distance (meters) between 
// two geo coordinates over the Earth’s surface using the ‘Haversine’ formula
// Input: Array of two geo coordinates (decimal degrees)
// Output: Distance between two geo coordinates (meters)
double Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_2(GeoCoord coord[2])
{
    double delta_lat = DEG2RAD(coord[1].lat - coord[0].lat);
    double delta_lon = DEG2RAD(coord[1].lon - coord[0].lon);

    double a = sin(delta_lat / 2) * sin(delta_lat / 2) + cos(DEG2RAD(coord[0].lat)) *
        cos(DEG2RAD(coord[1].lat)) * sin(delta_lon / 2) * sin(delta_lon / 2);

    double distance = atan2(sqrt(a), sqrt(1 - a)) * 2 * EARTH_RADIUS_M;

    return distance;
}

// This function calculates great-circle distance (meters) between 
// two geo coordinates over the Earth’s surface using the ‘Haversine’ formula
// Input: Array of two geo coordinates (decimal degrees)
// Output: Distance between two geo coordinates (meters)
double Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_3(GeoCoord coord[2])
{
    double lat1_rad = DEG2RAD(coord[0].lat);
    double lon1_rad = DEG2RAD(coord[0].lon);
    double lat2_rad = DEG2RAD(coord[1].lat);
    double lon2_rad = DEG2RAD(coord[1].lon);

    double haversine = (pow(sin((1.0 / 2) * (lat2_rad - lat1_rad)), 2)) + 
        ((cos(lat1_rad)) * (cos(lat2_rad)) * (pow(sin((1.0 / 2) * (lon2_rad - lon1_rad)), 2)));

    double distance = asin(min(1.0, sqrt(haversine))) * 2 * EARTH_RADIUS_M;

    return distance;
}

// This function calculates great-circle distance (meters) between 
// two geo coordinates over the Earth’s surface using the ‘Haversine’ formula
// Input: Array of two geo coordinates (decimal degrees)
// Output: Distance between two geo coordinates (meters)
double Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_4(GeoCoord coord[2])
{
    double lat1_rad = DEG2RAD(coord[0].lat);
    double lon1_rad = DEG2RAD(coord[0].lon);
    double lat2_rad = DEG2RAD(coord[1].lat);
    double lon2_rad = DEG2RAD(coord[1].lon);

    return acos(sin(lat1_rad) * sin(lat2_rad) + cos(lat1_rad) * cos(lat2_rad) * cos(lon2_rad - lon1_rad)) * EARTH_RADIUS_M;
}

// This function calculates great-circle distance (meters) between 
// two geo coordinates over the Earth’s surface using the ‘Haversine’ formula
// Input: Latitudes and longitudes of two geo coordinates (decimal degrees)
// Output: Distance between two geo coordinates (meters)
double Earth_Distance::GreatCircleDistanceBetweenTwoGeoCoord_5(double lat1, double lon1, double lat2, double lon2)
{
    double lat1_rad = DEG2RAD(lat1);
    double lon1_rad = DEG2RAD(lon1);
    double lat2_rad = DEG2RAD(lat2);
    double lon2_rad = DEG2RAD(lon2);

    double haversine = (pow(sin((1.0 / 2) * (lat2_rad - lat1_rad)), 2)) +
        ((cos(lat1_rad)) * (cos(lat2_rad)) * (pow(sin((1.0 / 2) * (lon2_rad - lon1_rad)), 2)));

    double distance = asin(min(1.0, sqrt(haversine))) * 2 * EARTH_RADIUS_M;

    return distance;
}

// This function calculates shortest great-circle distance (meters) over the Earth’s surface 
// between a line and a point, all of which are defined by respective geo coordinates.
// Input: Array of three geo coordinates (decimal degrees) where the first two members 
// define geo coordinates of line start and line end, respectively, and the third member 
// defines the geo coordinate of a point from which the shortest distance to the line is calculated.
// Output: Shortest distance between the line formed by first two geo coordinates and the third geo coordinate (meters)
double Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_1(GeoCoord coord[3])  
{
    GeoCoord line_start = { DEG2RAD(coord[0].lat), DEG2RAD(coord[0].lon) };
    GeoCoord line_end = { DEG2RAD(coord[1].lat), DEG2RAD(coord[1].lon) };
    GeoCoord point = { DEG2RAD(coord[2].lat), DEG2RAD(coord[2].lon) };

    Vector3D vector_start, vector_end, vector_point, cross_product;

    // Convert GeoCoord to Vector3D
    Geo2Vector3D(&vector_start, line_start);
    Geo2Vector3D(&vector_end, line_end);
    Geo2Vector3D(&vector_point, point);

    Vector3DCrossProduct(&cross_product, vector_start, vector_end);

    double earth_arc = EarthArc(fabs(CommonAngle(cross_product, vector_point) - M_PI_2));

    return earth_arc;
}

// This function calculates shortest great-circle distance (meters) over the Earth’s surface 
// between a line and a point, all of which are defined by respective geo coordinates.
// Input: Array of three geo coordinates (decimal degrees) where the first two members 
// define geo coordinates of line start and line end, respectively, and the third member 
// defines the geo coordinate of a point from which the shortest distance to the line is calculated.
// Output: Shortest distance between the line formed by first two geo coordinates and the third geo coordinate (meters)
// https://stackoverflow.com/questions/20231258/minimum-distance-between-a-point-and-a-line-in-latitude-longitude
double Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_2(GeoCoord coord[3])
{
    double lat1_rad = DEG2RAD(coord[0].lat);
    double lon1_rad = DEG2RAD(coord[0].lon);
    double lat2_rad = DEG2RAD(coord[1].lat);
    double lon2_rad = DEG2RAD(coord[1].lon);
    double lat3_rad = DEG2RAD(coord[2].lat);
    double lon3_rad = DEG2RAD(coord[2].lon);

    double y = sin(lon3_rad - lon1_rad) * cos(lat3_rad);
    double x = cos(lat1_rad) * sin(lat3_rad) - sin(lat1_rad) * cos(lat3_rad) * cos(lat3_rad - lat1_rad);

    double bearing1 = RAD2DEG(atan2(y, x));
    bearing1 = 360 - (double)(((int)bearing1 + 360) % 360);

    double y2 = sin(lon2_rad - lon1_rad) * cos(lat2_rad);
    double x2 = cos(lat1_rad) * sin(lat2_rad) - sin(lat1_rad) * cos(lat2_rad) * cos(lat2_rad - lat1_rad);

    double bearing2 = RAD2DEG(atan2(y2, x2));
    bearing2 = 360 - (double)(((int)bearing2 + 360) % 360);

    double delta_lon = lon3_rad - lon1_rad;

    double distance13 = acos(sin(lat1_rad) * sin(lat3_rad) + cos(lat1_rad) * cos(lat3_rad) * cos(delta_lon)) * EARTH_RADIUS_M;

    double shortest_distance = fabs(asin(sin(distance13 / EARTH_RADIUS_M) * sin(DEG2RAD(bearing1) - DEG2RAD(bearing2))) * EARTH_RADIUS_M);

    //cout << "Bearing 1: " << bearing1 << endl;
    //cout << "Bearing 2: " << bearing2 << endl;
    //cout << "Distance 13: " << distance13 << endl;
    //cout << "Shortest distance: " << shortest_distance << endl;

    return shortest_distance;
}

// This function calculates shortest great-circle distance (meters) over the Earth’s surface 
// between a line and a point, all of which are defined by respective geo coordinates.
// Input: Array of three geo coordinates (decimal degrees) where the first two members 
// define geo coordinates of line start and line end, respectively, and the third member 
// defines the geo coordinate of a point from which the shortest distance to the line is calculated.
// Output: Shortest distance between the line formed by first two geo coordinates and the third geo coordinate (meters)
// https://stackoverflow.com/questions/53131254/perpendicular-geo-distance-from-a-point-to-a-line-using-boost-geometry
double Earth_Distance::GreatCircleDistanceBetweenLineAndPoint_3(GeoCoord coord[3])
{
    double lat1 = DEG2RAD(coord[0].lat);
    double lon1 = DEG2RAD(coord[0].lon);
    double lat2 = DEG2RAD(coord[1].lat);
    double lon2 = DEG2RAD(coord[1].lon);
    double lat3 = DEG2RAD(coord[2].lat);
    double lon3 = DEG2RAD(coord[2].lon);

    // Let's work with a sphere of R = 1
    Vector3D OA(std::cos(lat1) * std::cos(lon1), std::cos(lat1) * std::sin(lon1), std::sin(lat1));
    Vector3D OB(std::cos(lat2) * std::cos(lon2), std::cos(lat2) * std::sin(lon2), std::sin(lat2));
    Vector3D OP(std::cos(lat3) * std::cos(lon3), std::cos(lat3) * std::sin(lon3), std::sin(lat3));

    // Plane OAB, defined by its perpendicular vector pp1
    Vector3D pp1 = CrossProduct(OA, OB);

    // Plane OPC
    Vector3D pp2 = CrossProduct(pp1, OP);

    // Planes intersection, defined by a line whose vector is ppi
    Vector3D ppi = CrossProduct(pp1, pp2);

    ppi.Normalize(); // Unitary vector

    //std::cout << "Distance AB = " << CalculateGreatCircleDistance(OA, OB, EARTH_RADIUS_M) << std::endl;
    //std::cout << "Distance AP = " << CalculateGreatCircleDistance(OA, OP, EARTH_RADIUS_M) << std::endl;
    //std::cout << "Distance BP = " << CalculateGreatCircleDistance(OB, OP, EARTH_RADIUS_M) << std::endl;

    double perpendicular_distance = CalculateGreatCircleDistance(OP, ppi, EARTH_RADIUS_M);

    //std::cout << "Perpendicular distance (on arc) = " << perpendicular_distance << std::endl;

    return perpendicular_distance;
}

Vector3D Earth_Distance::CrossProduct(const Vector3D& v1, const Vector3D& v2)
{
    return Vector3D(v1.y * v2.z - v2.y * v1.z,
        v1.z * v2.x - v2.z * v1.x,
        v1.x * v2.y - v2.x * v1.y);
}

double Earth_Distance::DotProduct(const Vector3D& v1, const Vector3D& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double Earth_Distance::CalculateGreatCircleDistance(const Vector3D& v1, const Vector3D& v2, double R)
{
    // Normalize, so we can pass any vectors
    Vector3D v1n = v1;
    v1n.Normalize();

    Vector3D v2n = v2;
    v2n.Normalize();

    Vector3D tmp = CrossProduct(v1n, v2n);

    // Minimum distance may be in one direction or the other
    double d1 = std::abs(R * std::atan2(tmp.Length(), DotProduct(v1n, v2n)));
    double d2 = std::abs(R * std::atan2(tmp.Length(), -DotProduct(v1n, v2n)));

    return std::min(std::abs(d1), std::abs(d2));
}