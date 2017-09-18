// Controller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "PID.hpp"

using namespace std;

int main()
{
	double desiredHeight;
	std::cout << "Desired Height: ";
	std::cin >> desiredHeight;

	/*
	* Code should start here.
	*/
	while (true)
	{
		double currentHeight = getHeight();

		if (desiredHeight == currentHeight) break;
		
		// Calculate thrust based on parameters
		double thrust = 0;

		// Set thrust
		setThrust(thrust);
	}
}

