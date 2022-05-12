// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file defines entry point of the application

#include <iostream>

#include "manager.h"

using namespace std;

int main()
{
	Manager manager("done");

	try
	{
		manager.Start();
	}
	catch (std::exception& e)
	{
		cout << e.what();
		return 0;
	}
}