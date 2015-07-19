//
//  UserName.cpp
//  ProblemSet1
//
//  Created by Karen van Eck on 02/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include "UserName.h"

UserName::UserName()
{
	makeNameVector("Anon");
}

UserName::UserName(std::string fullName)
{
	makeNameVector(fullName);
}

UserName::~UserName()
{
	
}

void UserName::makeNameVector(std::string fullName)
{
	//find first space
	size_t start = 0, end = fullName.find(' ');
	
	//as long as there are spaces
	while(end != std::string::npos)
	{
		//get word
		nameParts.push_back(fullName.substr(start, end-start));
		
		//search next space (of course only after already found space)
		start = end + 1;
		end = fullName.find(' ', start);
	}
	
	//last word
	nameParts.push_back(fullName.substr(start));
}
