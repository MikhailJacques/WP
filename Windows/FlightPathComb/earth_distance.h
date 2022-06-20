#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include "geo_point.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define RAD2DEG(r) ((r) * (180.0 / M_PI)) // Radians to Degrees
#define DEG2RAD(d) ((d) * (M_PI / 180.0)) // Degrees to Radians   ((d) * (std::acos(-1) / 180))

#define DEG2miniRAD     17.45
#define EPSILON 1E-10

//#define EARTH_RADIUS_KM 6371
//#define EARTH_RADIUS_M  6371000

#define EARTH_RADIUS_KM 6378.137
#define EARTH_RADIUS_M  6378137

using namespace std;

typedef struct
{
    double lat;
    double lon;
} GeoCoord;

typedef struct
{
    double x;
    double y;
    double z;
} CartCoord3D;

struct Vector3D
{
    double x, y, z;

    Vector3D() : x(0), y(0), z(0) {}

    Vector3D(double xd, double yd, double zd) : x(xd), y(yd), z(zd) {}

    double Length()
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    void Normalize()
    {
        double len = Length();
        x = x / len;
        y = y / len;
        z = z / len;
    }
};

class Earth_Distance
{   
private:

    static void Geo2Cart(CartCoord3D *lhs, GeoCoord rhs)
    {
        lhs->x = EARTH_RADIUS_M * cos(rhs.lat) * cos(rhs.lon);
        lhs->y = EARTH_RADIUS_M * cos(rhs.lat) * sin(rhs.lon);
        lhs->z = EARTH_RADIUS_M * sin(rhs.lat);
    }

    static void Cart2Vector3D(Vector3D *lhs, CartCoord3D rhs)
    {
        lhs->x = rhs.x;
        lhs->y = rhs.y;
        lhs->z = rhs.z;
    }

    static void Geo2Vector3D(Vector3D *lhs, GeoCoord rhs)
    {
        CartCoord3D CartCoord;

        // Convert input GeoCoord to CartCoord
        Geo2Cart(&CartCoord, rhs);

        // Convert CartCoord to Vector
        Cart2Vector3D(lhs, CartCoord);
    }

    static void Vector3DCrossProduct(Vector3D *Result, Vector3D lhs, Vector3D rhs)
    {
        Result->x = lhs.y * rhs.z - lhs.z * rhs.y;
        Result->y = lhs.z * rhs.x - lhs.x * rhs.z;
        Result->z = lhs.x * rhs.y - lhs.y * rhs.x;
    }

    static double EarthArc(double angle)
    {
        return fabs(angle) * EARTH_RADIUS_M;
    }

    static bool IsZero(double a)
    {
        return (fabs(a)) < EPSILON;
    }

    static bool IsZeroVector3D(Vector3D Vector)
    {
        return (IsZero(Vector.x) && IsZero(Vector.y) && IsZero(Vector.z));
    }

    static double Mod(double a, double b)
    {
        return (a >= 0 ? fmod(a, b) : b + fmod(a, b));
    }

    static double Mod2PI(double a)
    {
        return Mod(a, M_PI * 2.0);
    }

    static double BandPassMax(double New, double Max)
    {
        return New > Max ? Max : New < -Max ? -Max : New;
    }

    static double Acos(double a)
    {
        return acos(BandPassMax(a, 1 - EPSILON));
    }

    static double Vector3DProduct(Vector3D lhs, Vector3D rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
    }

    static double Sqrt(double a)
    {
        return (a < 0 ? 0 : sqrt(a));
    }

    static double Abs3D(double a, double b, double c)
    {
        return Sqrt(a * a + b * b + c * c);
    }

    static double AbsVector3D(Vector3D rhs)
    {
        return Abs3D(rhs.x, rhs.y, rhs.z);
    }

    // Finds the smaller angle (up to 180 degrees) between the vectors of mutual origin
    static double CommonAngle(Vector3D lhs, Vector3D rhs)
    {
        if (IsZeroVector3D(lhs) || IsZeroVector3D(rhs))
        {
            return 0;
        }

        return Mod2PI(Acos(Vector3DProduct(lhs, rhs) / (AbsVector3D(lhs) * AbsVector3D(rhs))));
    }

    static Vector3D CrossProduct(const Vector3D& v1, const Vector3D& v2);
    static double DotProduct(const Vector3D& v1, const Vector3D& v2);
    static double CalculateGreatCircleDistance(const Vector3D& v1, const Vector3D& v2, double R);

public:

    Earth_Distance(void) {};
    ~Earth_Distance(void) {};

    static GeoCoord FindGeoCoordAtDistanceFrom(GeoCoord start_point, double bearing_deg, double distance_km);

    static double EarthBearingBetweenTwoGeoCoord_1(GeoCoord coord[2]);
    static double EarthBearingBetweenTwoGeoCoord_2(GeoCoord coord[2]);
    static double EarthBearingBetweenTwoGeoCoord_3(double lat1, double lon1, double lat2, double lon2);

    static double GreatCircleDistanceBetweenTwoGeoCoord_1(GeoCoord coord[2]);
    static double GreatCircleDistanceBetweenTwoGeoCoord_2(GeoCoord coord[2]);
    static double GreatCircleDistanceBetweenTwoGeoCoord_3(GeoCoord coord[2]);
    static double GreatCircleDistanceBetweenTwoGeoCoord_4(GeoCoord coord[2]);
    static double GreatCircleDistanceBetweenTwoGeoCoord_5(double lat1, double lon1, double lat2, double lon2);

    static double GreatCircleDistanceBetweenLineAndPoint_1(GeoCoord coord[3]);
    static double GreatCircleDistanceBetweenLineAndPoint_2(GeoCoord coord[3]);
    static double GreatCircleDistanceBetweenLineAndPoint_3(GeoCoord coord[3]);
};