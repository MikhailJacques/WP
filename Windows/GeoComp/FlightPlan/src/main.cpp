// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file defines entry point of the application

#include <iostream>

#include "flight_plan.h"

int main()
{
    FlightPlan flight_plan;

	try
	{
		flight_plan.Start();
	}
	catch (std::exception& e)
	{
		cout << e.what();
		return 0;
	}
}