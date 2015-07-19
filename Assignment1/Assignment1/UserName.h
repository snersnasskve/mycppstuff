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
public:
	UserName();
	UserName(std::string fullName);
	~UserName();
	
	void showNames();
	
	//	For comparing names you need public getters
	std::vector<std::string> getNameVector();
	std::vector<std::string> getSoundexNameVector();
	
	bool operator==(UserName& otherName);

private:
	void makeNameVector(std::string fullName);
	void makeSoundexNameVector();	//	call makeNameVector first please
	
	void getSoundexMaster();
	std::string getSoundexForName(std::string nameString);

	std::vector<std::string> nameParts;
	std::vector<std::string> soundexNameParts;
	std::vector<std::string> soundexMaster;

};