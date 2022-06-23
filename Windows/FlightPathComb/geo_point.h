//// AUTHOR:		Mikhail Jacques
//// PROJECT:		WorldPerception
//// DOCUMENT:	None
//// DESCRIPTION: This file defines and geo coordinates object
//
//#pragma once
//
//class GeoCoord
//{
//private:
//
//	void Reset(void)
//	{
//		m_lat = 0.0;
//		m_lon = 0.0;
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
//	GeoCoord(double lat, double lon) :
//		m_lat(lat),
//		m_lon(lon) { }
//
//	// Copy constructor
//	GeoCoord(const GeoCoord& geo_point) :
//		m_lat(geo_point.m_lat),
//		m_lon(geo_point.m_lon) { }
//
//	// Overloaded assignment operator
//	GeoCoord& operator=(const GeoCoord& rhs)
//	{
//		if (this == &rhs)
//			return *this;
//
//		m_lat = rhs.m_lat;
//		m_lon = rhs.m_lon;
//
//		return *this;
//	}
//
//	~GeoCoord() {}
//
//	double m_lat;	// Range  [(-π/2), π/2] (Radians), default 0, [0.0, 90.0] degrees
//	double m_lon;	// Range [0, 2π] (Radians), default 0, [0.0, 180.0] degrees
//};