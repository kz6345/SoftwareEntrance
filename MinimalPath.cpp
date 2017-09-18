// MinimalPath.cpp : Defines the entry point for the console application.
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

	int row;
	int column;
	
	inputFile.open("sum.in");
	if (!inputFile)
	{
		std::cout << "Unalbe to open file";
		exit(1);
	}

	// Read row and column
	inputFile >> row;
	inputFile >> column;

	// Initialize the array of array
	int **pValues;
	pValues = new int*[row];
	for (int i = 0; i < row; i++)
	{
		pValues[i] = new int[column];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			inputFile >> pValues[i][j];
		}
	}

	inputFile.close();

	int result = pathValue(pValues, row, column, 0, 0);
	std::cout << "Minimal Path Value:";
	std::cout << result;

	outputFile.open("sum.out");
	outputFile << result;
	outputFile.close();
}

int pathValue(int** values, int row, int column, int r, int c)
{
	if ((r == row - 1) && (c == column - 1))
	{
		return values[row - 1][column - 1];
	}
	else
	{
		int rightValue = INT_MAX;
		int downValue = INT_MAX;
		if (r < row - 1)
		{
			rightValue = pathValue(values, row, column, r + 1, c);
		}
		if (c < column -1)
		{
			downValue = pathValue(values, row, column, r, c + 1);
		}

		if (rightValue < downValue)
		{
			return rightValue + values[r][c];
		}
		else
		{
			return downValue + values[r][c];
		}
	}
}
