//
//  Removing.cpp
//  ProblemSet1
//
//  Created by Karen van Eck on 20/02/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "Removing.h"

std::string CensorString1(std::string text, std::string remove)
{
	std::string result;
	for (int i = 0 ; 0 < text.length() ; i++)
	{
		if (remove.find(text[i]) != std::string::npos)
		{
			result += text[i];
		}
	}
	return result;
}