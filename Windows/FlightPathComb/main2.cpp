//
//
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//inline void Geo2Cart(FMCartCoord3D *lhs, GeoCoord rhs)
//{
//    lhs->x = EARTH_RADIUS_KM * cos(rhs.Lat) * cos(rhs.Lon);
//    lhs->y = EARTH_RADIUS_KM * cos(rhs.Lat) * sin(rhs.Lon);
//    lhs->z = EARTH_RADIUS_KM * sin(rhs.Lat);
//}
//
//inline void Cart2Vector3D(FMVector3D *lhs, FMCartCoord3D rhs)
//{
//    lhs->x = rhs.x;
//    lhs->y = rhs.y;
//    lhs->z = rhs.z;
//}
//
//inline void Geo2Vector3D(FMVector3D *lhs, GeoCoord rhs)
//{
//    FMCartCoord3D CartCoord;
//
//    // Convert the input GeoCoord to CartCoord
//    Geo2Cart(&CartCoord, rhs);
//
//    // Convert the CartCoord to Vector
//    Cart2Vector3D(lhs, CartCoord);
//}
//
//inline void FMVector3DCrossProduct(FMVector3D *Result, FMVector3D lhs, FMVector3D rhs)
//{
//    Result->x = lhs.y * rhs.z - lhs.z * rhs.y;
//    Result->y = lhs.z * rhs.x - lhs.x * rhs.z;
//    Result->z = lhs.x * rhs.y - lhs.y * rhs.x;
//}
//
//inline double FMEarthArc(double angle)
//{
//    return fabs(angle) * EARTH_RADIUS_KM;
//}
//
//inline bool FMIsZero(double a)
//{
//    return (fabs(a)) < EPSILON;
//}
//
//inline bool FMIsZeroVector3D(FMVector3D Vector)
//{
//   return (FMIsZero(Vector.x) && FMIsZero(Vector.y) && FMIsZero(Vector.z));
//}
//
//inline double FMMod(double a, double b)
//{
//    return (a >= 0 ? fmod(a, b) : b + fmod(a, b));
//}
//
//inline double FMMod2PI(double a)
//{
//    return FMMod(a, M_PI * 2.0);
//}
//
//inline double FMBandPassMax(double New, double Max)
//{
//    return New > Max ? Max : New < -Max ? -Max : New;
//}
//
//inline double FMAcos(double a)
//{
//    return acos(FMBandPassMax(a, 1 - EPSILON));
//}
//
//inline double FMVector3DProduct(FMVector3D lhs, FMVector3D rhs)
//{
//    return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z);
//}
//
//inline double FMSqrt(double a)
//{
//    return (a < 0 ? 0 : sqrt(a));
//}
//
//inline double FMAbs3D(double a, double b, double c)
//{
//    return FMSqrt(a * a + b * b + c * c);
//}
//
//inline double FMAbsVector3D(FMVector3D rhs)
//{
//    return FMAbs3D(rhs.x, rhs.y, rhs.z);
//}
//
//// Finfs the smaller angle (up to 180 degrees) between the vectors of mutual origin
//inline double FMCommonAngle(FMVector3D lhs, FMVector3D rhs)
//{
//    if (FMIsZeroVector3D(lhs) || FMIsZeroVector3D(rhs))
//    {
//        return 0;
//    }
//
//    return FMMod2PI(FMAcos(FMVector3DProduct(lhs, rhs) / FMAbsVector3D(lhs) * FMAbsVector3D(rhs)));
//}
//
//// dy for straight leg
//inline double FMEarthDistanceStraight(GeoCoord Start, GeoCoord End, GeoCoord Test)
//{
//    FMVector3D StartVec, EndVec, TestVec, CrossResult;
//
//    // Convert the GeoCoord to Vector
//    Geo2Vector3D(&StartVec, Start);
//    Geo2Vector3D(&EndVec, End);
//    Geo2Vector3D(&TestVec, Test);
//
//    FMVector3DCrossProduct(&CrossResult, StartVec, EndVec);
//
//    double earth_arc = FMEarthArc(fabs(FMCommonAngle(CrossResult, TestVec) - M_PI_2));
//
//    return earth_arc;
//}
//
//int main()
//{
//    GeoCoord wp1, wp2, point3;
//
//    // Omer's set 3
//    wp1.Lat = 32.2931005;
//    wp1.Lon = 34.8761684;
//
//    wp2.Lat = 32.2916992;
//    wp2.Lon = 34.8775470;
//
//    point3.Lat = 32.2910009;
//    point3.Lon = 34.8763937;
//
//    double distance = FMEarthDistanceStraight(wp1, wp2, point3);
//
//    return 0;
//}
