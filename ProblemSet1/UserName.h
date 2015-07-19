//
//  UserName.h
//  ProblemSet1
//
//  Created by Karen van Eck on 02/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

#ifndef __ProblemSet1__UserName__
#define __ProblemSet1__UserName__

#include <iostream>
#include <vector>

#endif /* defined(__ProblemSet1__UserName__) */

class UserName {
	
	UserName();
	UserName(std::string fullName);
	~UserName();
	
private:
	void makeNameVector(std::string fullName);
	
	std::vector<std::string> nameParts;
};