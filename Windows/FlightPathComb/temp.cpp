
// setw(x) - sets the field width to be used on output operations.
// setprecision(x) - sets the decimal precision to be used to format floating-point values on output operations.
// showpoint: forces the decimal portions of a floating-point variable to be displayed, even if it is not explicitly set.
// fixed: enforces that all floating-point numbers are output the same way. If precision is set to 4 places, 6.2, and 6.20 will both be output as 6.2000


//do
//{
//    cout << "Enter latitude: ";
//    cin >> latitude;

//    if ((latitude < -90.0) || (latitude > 90.0))
//    {
//        cout << "Invalid entry! Please try again." << endl;
//    }

//} while ((latitude < -90.0) || (latitude > 90.0));

//do
//{
//    cout << "Enter longitude: ";
//    cin >> longitude;

//    if ((longitude < -180.0) || (longitude > 180.0))
//    {
//        cout << "Invalid entry! Please try again." << endl;
//    }

//} while ((longitude < -180.0) || (longitude > 180.0));

//do
//{
//    cout << "Enter radius: ";
//    cin >> radius;

//    if ((radius < 20.0) || (radius > 200.0))
//    {
//        cout << "Invalid entry! Please try again." << endl;
//    }

//} while ((radius < 20.0) || (radius > 200.0));

//do
//{
//    cout << "Enter number of points: ";
//    cin >> num_of_points;

//    if ((num_of_points < 40) || (num_of_points > 360))
//    {
//        cout << "Invalid entry! Please try again." << endl;
//    }
//    else if ((num_of_points % 4) != 0)
//    {
//        cout << "Invalid entry! Please try again." << endl;
//        cout << "Number of points must be a multiple of number 4." << endl;
//    }
//} while ((num_of_points < 40) || (num_of_points > 360) || ((num_of_points % 4) != 0));



//unsigned short num_of_degrees_per_section = 360 / num_of_points;
//// Normalize radius
//radius /= denom;
//int ii = 0;
//// First quadrant
//for (; ii < 90; ii += num_of_degrees_per_section)
//{
//    GeoCoord geo_point((latitude + radius * cos(RAD2DEG(ii))), (longitude + radius * sin(RAD2DEG(ii))));
//    flight_path.push_back(geo_point);
//}
//// Second quadrant
//for (; ii < 180; ii += num_of_degrees_per_section)
//{
//    GeoCoord geo_point((latitude - radius * cos(RAD2DEG(180.0 - ii))), (longitude + radius * sin(RAD2DEG(180.0 - ii))));
//    flight_path.push_back(geo_point);
//}
//// Third quadrant
//for (; ii < 270; ii += num_of_degrees_per_section)
//{
//    GeoCoord geo_point((latitude - radius * cos(RAD2DEG(ii - 180.0))), (longitude - radius * sin(RAD2DEG(ii - 180.0))));
//    flight_path.push_back(geo_point);
//}
//// Fourth quadrant
//for (; ii < 360; ii += num_of_degrees_per_section)
//{
//    GeoCoord geo_point((latitude + radius * cos(RAD2DEG(360.0 - ii))), (longitude - radius * sin(RAD2DEG(360.0 - ii))));
//    flight_path.push_back(geo_point);
//}
//std::cout << "\nFligh path: \n";
//// Print out calculated navigation points
//std::for_each(std::begin(flight_path), std::end(flight_path), [](GeoCoord const& value) {
//    std::cout << setprecision(4) << fixed << showpoint << value.lat << " " << value.lon << "\n";
//    });


////========================================================================================
//// http://paulbourke.net/geometry/pointlineplane/source.c
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