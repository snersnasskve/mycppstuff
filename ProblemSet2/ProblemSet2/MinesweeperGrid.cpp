//
//  MinesweeperGrid.cpp
//  ProblemSet2
//
//  Created by Karen van Eck on 15/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

#include <vector>

#include "MinesweeperGrid.h"

using namespace std;

MinesweeperGrid::MinesweeperGrid()
{
	
}

MinesweeperGrid::~MinesweeperGrid()
{
	
}

GridOfInt MinesweeperGrid::MakeGridOfCounts(GridOfBool & bombLocations)
{
	GridOfInt clues;			//	A two by two grid showing how many bombs each site hits
	
	for (int row = 0 ; row < bombLocations.size() ; row ++)
	{
		vector<int> rowVector;
		for (int col = 0 ; col < bombLocations.at(row).size() ; col ++)
		{
			int cellValue = getCellValue(col, row, bombLocations);
			//cout << "Value at location " << row << ", " << col << " is " << cellValue << endl;
			rowVector.push_back(cellValue);
		}
		clues.push_back(rowVector);
	}
	return clues;
}


int MinesweeperGrid::getCellValue(int row, int col, GridOfBool bombLocations)
{
	int cellValue = 0;
	
	for (int rowVal = -1 ; rowVal < 2 ; rowVal++)
	{
		for (int colVal = -1 ; colVal < 2 ; colVal++)
		{
			if ((row + rowVal) >= 0 &&
				(col + colVal) >= 0 &&
				(row + rowVal) < bombLocations.size() &&
				(col + colVal) < bombLocations.at(row).size())
			{
				if (bombLocations.at(row + rowVal).at(col + colVal))
				{
					cellValue++;
				}
			}
		}
		
	}
	
	return cellValue;
}


void MinesweeperGrid::MakeRandomBoard(int rowSize, int colSize, GridOfBool &bombLocations)
{
	
	for (int row = 0 ; row < rowSize ; row++)
	{
		vector<bool> rowLocations;
		//rowLocations.reserve(colSize);
		for (int col = 0 ; col < colSize ; col++)
		{
			int random = (rand() % 5) ;		//	always 0 or 1
			bool bombHere = (0 == random) ? true : false;
			rowLocations.push_back(bombHere);
		}
		
		bombLocations.push_back(rowLocations);
		
	}
}

void MinesweeperGrid::printGameClues(GridOfInt & clues)
{
	cout << "Grid clues" << endl;
	
	for (int row = 0 ; row < clues.size() ; row ++)
	{
		for (int col = 0 ; col < clues.at(row).size() ; col ++)
		{
			cout << clues.at(row).at(col) << " ";
		}
		cout << endl;
	}
}
