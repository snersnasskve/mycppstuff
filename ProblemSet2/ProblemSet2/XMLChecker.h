//
//  XMLChecker.h
//  ProblemSet2
//
//  Created by Karen van Eck on 09/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

#ifndef __ProblemSet2__XMLChecker__
#define __ProblemSet2__XMLChecker__

#include <stack>
#include <iostream>
class XMLChecker
{
public:
	XMLChecker();
	~XMLChecker();
	
	bool IsCorrectlyNested(std::string htmlStr);
	
private:
	
	bool  manageTags(std::stack<std::string> &tags, std::string tagName, bool closingTag);

	long posNextControlChar(std::string stringToFind, std::string xmlString, long startPos);
	long posNextNonControlChar(std::string xmlString, long startPos);
	long getNextPos(long ltPos,long gtPos, long fwdPos, long wordPos);
	long getNextPosComp(long lowestPos, long compPos);
	std::string getWordFromPos(std::string htmlStr, long startPos);

};

#endif /* defined(__ProblemSet2__XMLChecker__) */
