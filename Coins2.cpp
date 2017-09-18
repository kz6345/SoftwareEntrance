// Coins.cpp : Defines the entry point for the console application.
//


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

	int value;
	int coins[4] = { 0,0,0,0 };

	inputFile.open("coins2.in");
	if (!inputFile)
	{
		std::cout << "Unalbe to open file";
		exit(1);
	}

	// Read value
	inputFile >> value;
	
	// Initialize the coins array
	for (int i = 0; i < 4; i++)
	{
		inputFile >> coins[i];
	}

	inputFile.close();

	int result = minCoins(coins, value);
	std::cout << "Minimal Coins:";
	std::cout << result;

	outputFile.open("coins2.out");
	outputFile << result;
	outputFile.close();
}

int minCoins(int coins[], int x)
{
	int finNum = INT_MAX;

	if (x == 0) 
	{
		return 0;
	}

	for (int i = 0; i < 4; i++)
	{
		if (coins[i] <= x) 
		{
			int num = minCoins(coins, x-coins[i]);
			if (num != INT_MAX && num + 1 < finNum) 
			{
				finNum = num + 1;
			}
		}
	}
	return finNum;
}

