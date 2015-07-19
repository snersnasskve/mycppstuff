//
//  main.m
//  Assignment1
//
//  Created by Karen van Eck on 24/02/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

#import <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <vector>
#include "UserName.h"

void problem1();
void problem2();
void problem3();
bool IsPerfect(int num);
void countVotes(int totalVotes, float errorPerc, int & votesFor, int & votesAgainst);


int cinInt(std::string prompt);
float cinFloat(std::string prompt);


int main(int argc, const char * argv[])
{
	
	//problem1();
	
	//problem2();
	
	problem3();
	
    return 0;
}

void problem3()
{
	UserName userName1 = UserName("Karen Prior");
	UserName userName2 = UserName("Prior Karn");
	if (userName1==(userName2))
	{
		userName1.showNames();
		std::cout << " is equal to "  << std::endl;
		userName2.showNames();
		
	}
	else
	{
		userName1.showNames();
		std::cout << " is NOT equal to "  << std::endl;
		userName2.showNames();
		
	}
}




void problem2()
{
	using namespace std;

	int numVoters		= cinInt	("Enter number of voters: ");
	float percSpread	= cinFloat	("Enter percentage spread between candidates: ");
	float errorPerc		= cinFloat	("nter voting error percentage:  ");

	
	float invalidTrials = 0;
	
	for (int counter = 0 ; counter < 500 ; counter ++)
	{
		int  aResultingVotes = 0;
		int  bResultingVotes = 0;

		int aVotes = (numVoters / 2) + (percSpread * (numVoters / 2));
		countVotes(aVotes, errorPerc, aResultingVotes, bResultingVotes);
	
		int bVotes = (numVoters / 2) - (percSpread * (numVoters / 2));
		countVotes(bVotes, errorPerc, bResultingVotes, aResultingVotes);
		
		if (bResultingVotes > aResultingVotes)
		{
			invalidTrials++;
		}
	}		//	500 trials
	
	float errorChance = (invalidTrials / 500.0f) * 100;
	cout << "Chance of an invalid election result after 500 trials = " << errorChance << endl;
	
}

//	Count votes
void countVotes(int totalVotes, float errorPerc, int & votesFor, int & votesAgainst)
{
for (int aCount = 0 ; aCount < totalVotes ; aCount ++)
{
	float randomError = (rand() % 100) ;
	if (randomError < (errorPerc * 100))
	{
		votesAgainst++;
	}
	else
	{
		votesFor++;
	}
	
}
}

void problem1()
{
for(int num = 1 ; num < 10000 ; num ++)
{
	if (IsPerfect(num))
	{
		std::cout << num << " is a perfect number" << std::endl;
	}
	else
	{
		//	std::cout << num << " is NOT a perfect number" << std::endl;
	}
}
}

//	A perfect number is where the sum of the factors is equal to the number = eg 6 with 1, 2, 3
bool IsPerfect(int num)
{
	bool perfect = false;
	int searchStart = 2;			//	No point in dividing by any number lower than 2
	int searchEnd = (num / 2) + 1;	//	a factor will never be more than half of the whole
	int sum = 1;					//	1 is a factor of every number
	for (int factor = searchStart ; factor < searchEnd ; factor++)
	{
		if (0 == (num % factor))
			sum += factor;
	}
	if (sum == num)
		perfect = true;
	return perfect;
}

int cinInt(std::string prompt)
{
	std::string valueString;
	std::cout << prompt;
	std::cin >> valueString;
	int valueInt = atoi(valueString.c_str());
	return valueInt;
}

float cinFloat(std::string prompt)
{
	std::string valueString;
	std::cout << prompt;
	std::cin >> valueString;
	float valueFloat = atof(valueString.c_str());
	return valueFloat;
}

