////========================================================================================
////
//// DistancePointLine Unit Test
//// Copyright (c) 2002, All rights reserved
////
//// Damian Coventry
//// Tuesday, 16 July 2002
////
//// Implementation of theory by Paul Bourke
////
////========================================================================================
//
//// http://paulbourke.net/geometry/pointlineplane/source.c
//
//#include <stdio.h>
//#include <math.h>
//
//typedef struct tagXYZ
//{
//    float X, Y, Z;
//} XYZ;
//
//float Magnitude(XYZ* Point1, XYZ* Point2)
//{
//    XYZ Vector;
//
//    Vector.X = Point2->X - Point1->X;
//    Vector.Y = Point2->Y - Point1->Y;
//    Vector.Z = Point2->Z - Point1->Z;
//
//    return (float)sqrt(Vector.X * Vector.X + Vector.Y * Vector.Y + Vector.Z * Vector.Z);
//}
//
//int DistancePointLine(XYZ* Point, XYZ* LineStart, XYZ* LineEnd, float* Distance)
//{
//    float LineMag;
//    float U;
//    XYZ Intersection;
//
//    LineMag = Magnitude(LineEnd, LineStart);
//
//    U = (((Point->X - LineStart->X) * (LineEnd->X - LineStart->X)) +
//        ((Point->Y - LineStart->Y) * (LineEnd->Y - LineStart->Y)) +
//        ((Point->Z - LineStart->Z) * (LineEnd->Z - LineStart->Z))) /
//        (LineMag * LineMag);
//
//    if (U < 0.0f || U > 1.0f)
//        return 0;   // closest point does not fall within the line segment
//
//    Intersection.X = LineStart->X + U * (LineEnd->X - LineStart->X);
//    Intersection.Y = LineStart->Y + U * (LineEnd->Y - LineStart->Y);
//    Intersection.Z = LineStart->Z + U * (LineEnd->Z - LineStart->Z);
//
//    *Distance = Magnitude(Point, &Intersection);
//
//    return 1;
//}
//
//void main(void)
//{
//    XYZ LineStart, LineEnd, Point;
//    float Distance;
//
//    LineStart.X = 50.0f; LineStart.Y = 80.0f; LineStart.Z = 300.0f;
//    LineEnd.X = 50.0f; LineEnd.Y = -800.0f; LineEnd.Z = 1000.0f;
//    Point.X = 20.0f; Point.Y = 1000.0f; Point.Z = 400.0f;
//
//    if (DistancePointLine(&Point, &LineStart, &LineEnd, &Distance))
//        printf("closest point falls within line segment, distance = %f\n", Distance);
//    else
//        printf("closest point does not fall within line segment\n");
//
//    LineStart.X = 0.0f; LineStart.Y = 0.0f; LineStart.Z = 50.0f;
//    LineEnd.X = 0.0f; LineEnd.Y = 0.0f; LineEnd.Z = -50.0f;
//    Point.X = 10.0f; Point.Y = 50.0f; Point.Z = 10.0f;
//
//    if (DistancePointLine(&Point, &LineStart, &LineEnd, &Distance))
//        printf("closest point falls within line segment, distance = %f\n", Distance);
//    else
//        printf("closest point does not fall within line segment\n");
//}


//// https://stackoverflow.com/questions/32771458/distance-from-lat-lng-point-to-minor-arc-segment
//double GreatCircleDistanceBetweenLineAndPoint_1(GeoCoord coord[3])
//{
//    double lat1 = DEG2RAD(coord[0].lat);
//    double lon1 = DEG2RAD(coord[0].lon);
//    double lat2 = DEG2RAD(coord[1].lat);
//    double lon2 = DEG2RAD(coord[1].lon);
//    double lat3 = DEG2RAD(coord[2].lat);
//    double lon3 = DEG2RAD(coord[2].lon);
//
//    // Earth's radius in meters
//    double R = EARTH_RADIUS_M;
//
//    // Prerequisites for the formulas
//    double bear12 = EarthBearingBetweenTwoGeoCoord_5(lat1, lon1, lat2, lon2);
//    double bear13 = EarthBearingBetweenTwoGeoCoord_5(lat1, lon1, lat3, lon3);
//    double dis13 = GreatCircleDistanceBetweenTwoGeoCoord_6(lat1, lon1, lat3, lon3);
//
//    // Is relative bearing obtuse?
//    if (abs(bear13 - bear12) > (M_PI / 2))
//        return dis13;
//
//    // Find the cross-track distance.
//    double dxt = asin(sin(dis13 / R) * sin(bear13 - bear12)) * R;
//
//    // Is p4 beyond the arc?
//    double dis12 = GreatCircleDistanceBetweenTwoGeoCoord_6(lat1, lon1, lat2, lon2);
//    double dis14 = acos(cos(dis13 / R) / cos(dxt / R)) * R;
//
//    if (dis14 > dis12)
//    {
//        return GreatCircleDistanceBetweenTwoGeoCoord_6(lat2, lon2, lat3, lon3);
//    }
//
//    double distance = abs(dxt);
//
//    return distance;
//}