//
//  main.m
//  ProblemSet2
//
//  Created by Karen van Eck on 07/03/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <fstream>
#include "XMLChecker.h"
#include "MinesweeperGrid.h"

using namespace std;

typedef map<string, int>MapOfInt;


struct eMailMsg {
	string to; // i.e. "professor@stanford.edu"
	string from; // i.e. "student@stanford.edu"
	string message; // body of message
	string subject; // i.e. "CS106 Rocks!"
	int date; // date email was sent
	int time; // time email was sent
};

void reverseQueue(queue<eMailMsg> &mailQueue);
void putEmailsInQueue(vector<eMailMsg>  &mailList, queue<eMailMsg> &mailQueue);

void makeSomeEmails(vector<eMailMsg>  &mailList);
void removeSpam(vector<eMailMsg>  &mailList);

char MostFrequentCharacter(ifstream &inputStream, int &numOccurrences);
void buildLetterMap(ifstream &inputStream, MapOfInt &letterMap);
char getMostPopularChar(MapOfInt &letterMap);

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();


string getFilePath();

int main(int argc, const char * argv[])
{
	//problem1();
	//problem2();
	//problem3();
	//problem4();
	problem5();
	
    return 0;
}

void problem5()
{
	MinesweeperGrid minesweeperGrid;
	GridOfBool bombLocations;
	minesweeperGrid.MakeRandomBoard(5, 5, bombLocations);
	GridOfInt gameClues =  minesweeperGrid.MakeGridOfCounts(bombLocations);
	minesweeperGrid.printGameClues(gameClues);
	
}



void problem4()
{
	string filePath = getFilePath();
	ifstream inputStream(filePath.c_str(), ios::in);
	
	int numOccurrences = 0;
	char freqChar = MostFrequentCharacter(inputStream, numOccurrences);
	
	cout << "The letter " << freqChar << " occurs most frequently" << endl;
}


char MostFrequentCharacter(ifstream &inputStream, int &numOccurrences)
{
	MapOfInt letterMap;
	
	//	build the letter map
	buildLetterMap(inputStream, letterMap);
	
	//	map looks successful - now to read
	char popularChar = getMostPopularChar(letterMap);
	return popularChar;
}


void buildLetterMap(ifstream &inputStream, MapOfInt &letterMap)
{
	
	char inChar;
	while ((inChar = inputStream.get()) > 0)
	{
		char lowerChar = tolower(inChar);
		string stringChar = string(&lowerChar);
		if (stringChar.compare("a") >= 0 && stringChar.compare("z") <= 0)
		{
			//	This is a letter
			int letterCount = 0;
			//	now do the mapping
			MapOfInt::iterator foundValuePtr = letterMap.find(stringChar);
			if (foundValuePtr != letterMap.end())
			{
				letterCount = (foundValuePtr->second);
			}
			letterCount++;
			if (foundValuePtr != letterMap.end())
			{
				foundValuePtr->second = letterCount;
			}
			else
			{
				letterMap.insert(pair<string, int>(stringChar, letterCount));
			}
		}
	}
}

char getMostPopularChar(MapOfInt &letterMap)
{
	string	popularString;
	int		popularCount = 0;
	for (MapOfInt::iterator mapIter = letterMap.begin() ; mapIter != letterMap.end() ; mapIter++)
	{
		char tempFirst = (mapIter->first)[0];
		cout << tempFirst << " : " << mapIter->second << endl;
		if (mapIter->second > popularCount)
		{
			popularCount = mapIter->second;
			popularString = mapIter->first;
		}
	}
	cout << "And the winner is: " << popularString.c_str()[0] << " with " << popularCount << " occurences!"  << endl;

	return popularString.c_str()[0];
}

void problem3()
{
	//	Read file name
	string filePath = getFilePath();
	ifstream inputStream(filePath.c_str(), ios::in);
	//	Read file contents into a string
	string htmlString = "";
	string line;
	while (std::getline(inputStream, line))
	{
		htmlString += line;
	}
	//	Call xml checker
	XMLChecker xmlChecker;
	bool correct = xmlChecker.IsCorrectlyNested( htmlString);
	if (correct)
		cout << "Xml is valid" << endl;
	else
		cout << "Xml is invalid - please sort" << endl;
		
	//	boom
}

void problem2()
{
	vector<eMailMsg> mailList;
	queue<eMailMsg> mailQueue;
	makeSomeEmails(mailList);
	putEmailsInQueue(mailList, mailQueue);
	
	cout << "Before:" << endl;
	
	for (long i = (mailQueue.size() -1) ; i >= 0  ; i--)
	{
		cout << "Subject:" << mailQueue.front().subject << endl;
		mailQueue.pop();
	}
	
	cout << "\nAfter:" << endl;
	
	putEmailsInQueue(mailList, mailQueue);
	reverseQueue(mailQueue);
	
	for (long i = (mailQueue.size() -1) ; i >= 0  ; i--)
	{
		cout << "Subject:" << mailQueue.front().subject << endl;
		mailQueue.pop();
	}
	
}


void reverseQueue(queue<eMailMsg> &mailQueue)
{
	stack<eMailMsg> mailStack;
	
	for (long i = (mailQueue.size() -1) ; i >= 0  ; i--)
	{
		mailStack.push(mailQueue.front());
		mailQueue.pop();
	}

	
	for (long i =  (mailStack.size() - 1) ; i >= 0  ; i--)
	{
		mailQueue.push(mailStack.top());
		mailStack.pop();
	}

}

void putEmailsInQueue(vector<eMailMsg>  &mailList, queue<eMailMsg> &mailQueue)
{
	for (std::vector<eMailMsg>::iterator it = mailList.begin() ; it != mailList.end() ; it++)
	{
		mailQueue.push(*it);
	}
	

}


void problem1()
{
	vector <eMailMsg>  mailList;
	makeSomeEmails(mailList);
	removeSpam(mailList);
	
	for (int i = 0 ; i < mailList.size() ; i++)
	{
		cout << "Subject:" << mailList.at(i).subject << endl;
	}

}


void removeSpam(vector<eMailMsg>  &mailList)
{
	for (std::vector<eMailMsg>::iterator it = mailList.end() ; it != mailList.begin() ; it--)
	{
		if ((it->subject).find("SPAM") != string::npos)
		{
			mailList.erase(it);
		}
	}

}



void makeSomeEmails(vector<eMailMsg>  &mailList)
{
	
	eMailMsg msg1;
	msg1.to			= "Fred";		msg1.from = "Karen";
	msg1.message	= "This is a story about a boy";
	msg1.subject	= "Boy";
	msg1.date		= 7667;			msg1.time = 8776;
	mailList.push_back(msg1);
	
	eMailMsg msg2;
	msg2.to			= "Joe";		msg2.from = "Karen";
	msg2.message	= "This is a story about a girl";
	msg2.subject	= " Girl";
	msg2.date		= 7667;			msg2.time = 8776;
	mailList.push_back(msg2);

	eMailMsg msg3;
	msg3.to			= "Jack";		msg3.from = "Karen";
	msg3.message	= "This is a story about a cow";
	msg3.subject	= "SPAM Cow";
	msg3.date		= 7667;			msg3.time = 8776;
	mailList.push_back(msg3);

	eMailMsg msg4;
	msg4.to			= "Jenny";		msg4.from = "Karen";
	msg4.message	= "This is a story about a pig";
	msg4.subject	= "Pig";
	msg4.date		= 7667;			msg4.time = 8776;
	mailList.push_back(msg4);

	eMailMsg msg5;
	msg5.to			= "John";		msg5.from = "Karen";
	msg5.message	= "This is a story about a goat";
	msg5.subject	= "Goat";
	msg5.date		= 7667;			msg5.time = 8776;
	mailList.push_back(msg5);

	eMailMsg msg6;
	msg6.to			= "Jill";		msg6.from = "Karen";
	msg6.message	= "This is a story about a kitten";
	msg6.subject	= "Kitten";
	msg6.date		= 7667;			msg6.time = 8776;
	mailList.push_back(msg6);
	
	
}


string getFilePath()
{
	string fileName;
	cout << "Enter file name: " ;
	cin >> fileName;
	cout << endl;
	string filePath = "/Users/admin/Desktop/" + fileName;
	return filePath;
}
