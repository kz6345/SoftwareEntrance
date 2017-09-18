#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	double dollars;

	inputFile.open("coins1.in");
	if (!inputFile)
	{
		std::cout << "Unalbe to open file";
		exit(1);
	}

	// Read value
	inputFile >> dollars;
	inputFile.close();

	outputFile.open("coins1.out");

	int cents = (int)(dollars * 100);

	if (cents > 0)
	{
		int noQuarters = cents % 25;
		int numOfQuarters = (cents - noQuarters) / 25;

		int noDimes = noQuarters % 10;
		int numOfDimes = (noQuarters - noDimes) / 10;

		int noNickels = noDimes % 5;
		int numOfNickels = (noDimes - noNickels) / 5;

		int numOfPennies = noNickels;

		outputFile << (numOfQuarters + numOfDimes + numOfNickels + numOfPennies);
	}
	else
	{
		outputFile << "0";
	}

	outputFile.close();
}



