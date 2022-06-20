
// setw(x) - sets the field width to be used on output operations.
// setprecision(x) - sets the decimal precision to be used to format floating-point values on output operations.
// showpoint: forces the decimal portions of a floating-point variable to be displayed, even if it is not explicitly set.
// fixed: enforces that all floating-point numbers are output the same way. If precision is set to 4 places, 6.2, and 6.20 will both be output as 6.2000


//const unsigned int denom = 100000;      // 
//double latitude = 32.6363504;           // User defined parameter, [-90.0, 90.0] degrees         
//double longitude = 35.0475073;          // User defined parameter, [-180.0, 180.0] degrees   
//double radius = 50.0;                   // User defined parameter, [20.0, 200.0] meters
//unsigned short num_of_points = 120;     // User defined parameter, [40, 360] meters, must be a multiple of 4
//vector<GeoCoord> flight_path;          // Stores navigation points around circular flight path

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