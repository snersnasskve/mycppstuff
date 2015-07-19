//
//  MinesweeperGrid.h
//  ProblemSet2
//
//  Created by Karen van Eck on 15/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

//	Ideally we want this whole Grid stuff to be located here so calling class has no idea of the board structure, it only knows a row no and a col no
//	This is cos I want to call it from Objective C

#ifndef __ProblemSet2__MinesweeperGrid__
#define __ProblemSet2__MinesweeperGrid__

#include <iostream>
#include <vector>

typedef std::vector< std::vector< bool  > >GridOfBool;
typedef std::vector< std::vector< int   > >GridOfInt;

class MinesweeperGrid
{
public:
	MinesweeperGrid();
	~MinesweeperGrid();
	


	GridOfInt MakeGridOfCounts(GridOfBool & bombLocations);		//	passing grid of int by copy as that is what excercise requires
	void MakeRandomBoard(int rowSize, int colSize, GridOfBool &bombLocations);
	void printGameClues(GridOfInt & clues);
	
private:
	int getCellValue(int row, int col, GridOfBool bombLocations);
};
#endif /* defined(__ProblemSet2__MinesweeperGrid__) */
