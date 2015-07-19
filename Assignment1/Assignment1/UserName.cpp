//
//  UserName.cpp
//  ProblemSet1
//
//  Created by Karen van Eck on 02/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//
//	Soundex system, patented by Margaret O'Dell
//	and Robert C. Russell in 1918
//	Scroll down for full description

#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include "UserName.h"

UserName::UserName()
{
	makeNameVector("Anon");
	getSoundexMaster();
	makeSoundexNameVector();
}

UserName::UserName(std::string fullName)
{
	makeNameVector(fullName);
	getSoundexMaster();
	makeSoundexNameVector();
}

UserName::~UserName()
{
	
}

//	Now all we need to do is overload operator ==

std::vector<std::string> UserName::getNameVector()
{
	return nameParts;
}

std::vector<std::string> UserName::getSoundexNameVector()
{
	return soundexNameParts;
}

bool UserName::operator==(UserName& otherName)
{
	bool matchFound = true;
	//	Get otherName's nameParts
	//	Iterate through and check that each exists locally
	
	//	Match soundex names
	std::vector<std::string> otherNameParts = otherName.getSoundexNameVector();
	
	for(std::vector<std::string>::const_iterator otherNameIter=
		otherNameParts.begin(); otherNameIter!=otherNameParts.end(); ++otherNameIter)
	{
		std::cout << * otherNameIter << std::endl;
		if (std::find(soundexNameParts.begin(), soundexNameParts.end(), *otherNameIter)==soundexNameParts.end())
		{
			matchFound = false;
		}
	}
	//	We can also do name truncations and names which have 3 parts, but that is another day
	return matchFound;
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

void UserName::makeSoundexNameVector()
{
	//	So this works off name parts - if its empty you'll get nowt
	for(std::vector<std::string>::const_iterator iter=
		nameParts.begin(); iter!=nameParts.end(); ++iter)
	{
		soundexNameParts.push_back(getSoundexForName(*iter));
	}
}


void UserName::getSoundexMaster()
{
	std::string soundexMasterArr[] = {"aeiouhwy", "bfpv", "cgjkqsxz", "dt", "mn", "l", "r"};
	for (int i = 0 ; i < 7 ; i++)
	{
		soundexMaster.push_back(soundexMasterArr[i]);
	}
}

std::string UserName::getSoundexForName(std::string nameString)
{
	std::stringstream soundex;
	soundex << nameString.substr(0, 1);
	int soundexLastChar = -1;
	
	//	Already used the initial so ignore 0
	for (int nameCounter = 1 ; nameCounter < nameString.length() ; ++nameCounter)
	{
		//	Ignore zeroes as they are not collected
		for (int soundCounter = 1 ; soundCounter <  soundexMaster.size(); ++soundCounter)
		{
			//	If the letter is in this soundex group
			//			and you should not have duplicatate
			if ((soundexMaster.at(soundCounter).find(tolower(nameString[nameCounter])) != std::string::npos)
				&& (soundCounter!= soundexLastChar))
			{
				soundex <<  soundCounter;
				soundexLastChar = soundCounter;
			}
		}
	}
	while (soundex.str().length() < 4)
		soundex << "0";
	return soundex.str();
}

//	Iterate through name parts and output the Soundex values
void  UserName::showNames()
{
	for(std::vector<std::string>::const_iterator iter=
		nameParts.begin(); iter!=nameParts.end(); ++iter)
		std::cout << "Full Name: " << *iter << ", Soundex Name: " << getSoundexForName(*iter) << '\n';
}

/*
 All Soundex codes have the same format (an uppercase letter followed by three digits e.g. Z452 or
 V200). The Soundex algorithm converts a surname to a code using these steps:
 1. Keep the first letter of the surname (convert to uppercase if necessary)
 2. Convert all other letters in the surname to a digit using the table below (discard any nonletter
 characters: dashes, spaces, and so on)
 0 A E I O U H W Y
 1 B F P V
 2 C G J K Q S X Z
 3 D T
 4 M N
 5 L
 6 R
 3. Remove any consecutive duplicate digits (e.g. A122235 becomes A1235)
 4. Remove any zeros
 5. Make resulting code exactly length 4 by truncating or padding with zeros
*/