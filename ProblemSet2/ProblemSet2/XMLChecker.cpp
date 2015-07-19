 //
//  XMLChecker.cpp
//  ProblemSet2
//
//  Created by Karen van Eck on 09/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//


#include <stack>
#include "XMLChecker.h"

using namespace std;


XMLChecker::XMLChecker()
{
	
}
XMLChecker::~XMLChecker()
{
	
}

//	method 1
//	collect opening tags
//	collect closing tags
//	ensure stacks match in order

//	method 2
//	march through the strinng
//	every time you find an opening tag, add to stack
//	every time you find a closing tag, ensure it marries the top of the stack then pop,
//	any time results are not as expected - bin em

//	method 2 will be more useful if you actually decide to keep the data between tags - which we hope to one day

bool XMLChecker::IsCorrectlyNested(string htmlStr)
{
	stack<string> tags;
	
	bool correct = true;
	
	long tagStartPos = 0;
	long fullLength = htmlStr.length();
	cout << "file length = " << fullLength << endl;
	long currentPos = posNextControlChar("<", htmlStr, 0);
	bool readingWords	= false;		//	If we're reading words we want to just skip to end of them
	bool closingTag		= false;
	while (currentPos != string::npos && currentPos != -1 && currentPos < fullLength && correct)
	{
		long ltPos		= posNextControlChar	( "<", htmlStr, currentPos);
		long gtPos		= posNextControlChar	( ">", htmlStr, currentPos);
		long fwdPos		= posNextControlChar	( "/", htmlStr, currentPos);
		long wordPos	= posNextNonControlChar	(  htmlStr, currentPos);
		if (readingWords)
		{
			wordPos = fullLength;	//	If we're reading words we want to just skip to end of them
		}
		long nextPos = getNextPos(ltPos, gtPos, fwdPos, wordPos);
		if (-1 == nextPos)
		{
			//	All done
			readingWords = false;
		}
		else if (nextPos == ltPos)
		{
			//	Process opening tag
			readingWords	= false;
			closingTag		= false;
			tagStartPos		= nextPos + 1;
				currentPos = nextPos;
		}
		else if (nextPos == gtPos)
		{
			//	Process closing tag
			
			string tagName	= getWordFromPos(htmlStr, tagStartPos);
			correct = manageTags(tags, tagName, closingTag);

			readingWords = false;
			currentPos		= nextPos;
		}
		else if (nextPos == fwdPos)
		{
			//	Process end tag
			readingWords	= false;
			closingTag		= true;
			currentPos		= fwdPos;
	}
		else if (nextPos == wordPos )
		{
			if (!readingWords)
			{
				tagStartPos = wordPos;
				readingWords = true;
			}
			//	Process word tag
			currentPos = wordPos;
		}
		currentPos ++;
	//	Is the next control char (<> or /) after pos a / - if so then this is a closing tag
		//	If closing tag and there are non-space characters between, then this is a tag with nothing nested
		//	Get the tag name
		
		
		//	Get the characters up to the next closing tag
		//	Get the characters up to the next opening tag
		//	Which comes first?
		
		//	Process start tag
		//		or
		//	Process end tag
		
	}

	if (tags.size() != 0)
	{
		correct = false;
	}
	
	return correct;
}

bool   XMLChecker::manageTags(stack<string> &tags, string tagName, bool closingTag)
{
	bool correct = true;
	
	if (closingTag)
	{
		//	Make sure the last thing on the stack is tagName
		if (tags.top().compare(tagName) == 0)
		{
			//	Pop it
			tags.pop();
		}
		else
		{
			correct = false;
		}
		
	}
	else
	{
		tags.push(tagName);
	}
	
	return correct;
}




long XMLChecker::posNextControlChar(string stringToFind, string xmlString, long startPos)
{
	long foundPos = xmlString.find(stringToFind, startPos);
	return foundPos;
}

long XMLChecker::posNextNonControlChar(string xmlString, long startPos)
{
	long foundPos = xmlString.find_first_not_of("<>/ ", startPos);
	return foundPos;
}

//	This is just to figure out - what next
//	Returns the next position we care about
long XMLChecker::getNextPos(long ltPos,long gtPos, long fwdPos, long wordPos)
{
	long lowestPos = -1;
	lowestPos = getNextPosComp(lowestPos, ltPos);
	lowestPos = getNextPosComp(lowestPos, gtPos);
	lowestPos = getNextPosComp(lowestPos, fwdPos);
	lowestPos = getNextPosComp(lowestPos, wordPos);
	return lowestPos;
}

long XMLChecker::getNextPosComp(long lowestPos, long compPos)
{
	if (compPos != string::npos &&
		(-1 == lowestPos || compPos < lowestPos)
		)
	{
		lowestPos = compPos;
	}
	return lowestPos;
}

string XMLChecker::getWordFromPos(string htmlStr, long startPos)
{
	long spacePos = posNextControlChar(" ", htmlStr, startPos);
	long gtPos    = posNextControlChar(">", htmlStr, startPos);
	long fwdPos   = posNextControlChar("/", htmlStr, startPos);
	long wordLength = (getNextPos(spacePos, gtPos, fwdPos, fwdPos)) - startPos;
	return htmlStr.substr(startPos, wordLength);
}