// AUTHOR:		Mikhail Jacques
// PROJECT:		Fun
// DOCUMENT:	None
// DESCRIPTION: This file defines and geo coordinates object

#pragma once

#include <iomanip>
#include <iostream>

class GEO_POINT
{
	private:

		void Reset(void)
		{
			m_latitude = 0.0;
			m_longitude = 0.0;
		}

	public:

		GEO_POINT()
		{
			Reset();
		}

		// Constructor
		GEO_POINT(double latitude, double longitude) :
			m_latitude(latitude),
			m_longitude(longitude) { }

		// Copy constructor
		GEO_POINT(const GEO_POINT& geo_point) :
			m_latitude(geo_point.m_latitude),
			m_longitude(geo_point.m_longitude) { }

		// Overloaded assignment operator
		GEO_POINT& operator=(const GEO_POINT& rhs)
		{
			if (this == &rhs)
				return *this;

			m_latitude = rhs.m_latitude;
			m_latitude = rhs.m_latitude;

			return *this;
		}

		~GEO_POINT() {}

		double m_latitude;		// Range  [(-π/2), π/2] (Radians), default 0, [0.0, 90.0] degrees
		double m_longitude;		// Range [0, 2π] (Radians), default 0, [0.0, 180.0] degrees
};
