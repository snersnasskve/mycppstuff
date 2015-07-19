//
//  main.cpp
//  stl test 2
//
//  Created by Karen van Eck on 23/09/2012.
//  Copyright (c) 2012 Karen van Eck. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{

	
	vector<int>              myVec;
	vector<int>::iterator    item;
	//	Woohoo examples which dont compile
	ostream_iterator<int>    out(cout," ");
	// generate array
	for ( long i=0; i<10; i++ )
		myVec.push_back(i);
	// shuffle the array
	random_shuffle( myVec.begin(), myVec.end() );
	copy( myVec.begin(), myVec.end(), out );
	// sort the array in ascending order
	sort( myVec.begin(), myVec.end() );
	copy( myVec.begin(), myVec.end(), out );   return 0;
}

