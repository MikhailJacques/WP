//// AUTHOR:		Mikhail Jacques
//// PROJECT:		Fun
//// DOCUMENT:	None
//// DESCRIPTION: This file defines and geo coordinates object
//
//#pragma once
//
//
//
//class GeoCoord
//{
//private:
//
//	void Reset(void)
//	{
//		Lat = 0.0;
//		Lon = 0.0;
//	}
//
//public:
//
//	GeoCoord()
//	{
//		Reset();
//	}
//
//	// Constructor
//	GeoCoord(double latitude, double longitude) :
//		Lat(latitude),
//		Lon(longitude) { }
//
//	// Copy constructor
//	GeoCoord(const GeoCoord& geo_point) :
//		Lat(geo_point.lat),
//		Lon(geo_point.lon) { }
//
//	// Overloaded assignment operator
//	GeoCoord& operator=(const GeoCoord& rhs)
//	{
//		if (this == &rhs)
//			return *this;
//
//		Lat = rhs.lat;
//		Lat = rhs.lat;
//
//		return *this;
//	}
//
//	~GeoCoord() {}
//
//	double Lat;		// Range  [(-π/2), π/2] (Radians), default 0, [0.0, 90.0] degrees
//	double Lon;		// Range [0, 2π] (Radians), default 0, [0.0, 180.0] degrees
//};
//
