//
//  main.m
//  ProblemSet1
//
//  Created by Karen van Eck on 20/02/2015.
//  Copyright (c) 2015 kve. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>


struct scores {int min; int max; float avg;};


std::string CensorString1(std::string text, std::string remove);

void		CensorString2(std::string & text, std::string remove);

std::string getFilePath();

void	problem1();
scores	problem2();
void	problem3();

int main(int argc, const char * argv[])
{

	    
			
	//problem1();
	//scores myScores = problem2();
	problem3();
	
 return 0;
}

void problem3()
{
	//	Count characters in a file
	using namespace std;
	vector<int> letters(26);
	string filePath = getFilePath();
	ifstream inputStream(filePath.c_str(), ios::in);

	int inChar;
	
	while ((inChar = inputStream.get()) > 0)
	{
		if (inChar > 64 && inChar < 91)
			letters[(inChar -65)] += 1;
		if (inChar > 96 && inChar < 123)
			letters[(inChar -97)] += 1;
	}
	
	int letterCounter = 0;
	for (vector<int>::iterator it = letters.begin() ; it != letters.end() ; ++it)
	{
		//	Assign an int to a char = makes it into a letter
		char asciiVal = (letterCounter + 65);
		cout << asciiVal << " : " << *it << endl;
		
		letterCounter ++;
	}
}

scores problem2()
{
	std::string filePath = getFilePath();
	std::ifstream inputStream(filePath.c_str(), std::ios::in);
	
	std::string line;
	int min = 101;
	int max = 0;
	int sum = 0;
	int count = 0;
	scores myScores;
	while (std::getline(inputStream, line))
	{
  		int grade = atoi(line.c_str());
		if (grade > max)
			max = grade;
		if (grade < min)
			min = grade;
		sum += grade;
		count ++;
		
	}
	myScores.min = min;
	myScores.max = max;
	myScores.avg = (float) sum / count;
	
	
	return myScores;
}



void problem1()
{
	std::string censored1 = CensorString1("Stanford University", "nt");
	std::cout << censored1 << std::endl;
  	std::string censored2 = CensorString1("Llamas like to laugh", "la");
	std::cout << censored2 << std::endl;
	
 	std::string censored3 = "Stanford University";
	CensorString2(censored3, "nt");
	std::cout << censored3 << std::endl;
  	std::string censored4 = "Llamas like to laugh";
	CensorString2(censored4, "la");
	std::cout << censored4 << std::endl;
	
}

std::string CensorString1(std::string text, std::string remove)
{
	std::string result;
	for (int i = 0 ; i < text.length() ; i++)
	{
		if (remove.find(text[i]) == std::string::npos)
		{
			result += text[i];
		}
	}
	return result;
}

void		CensorString2(std::string & text, std::string remove)
{
	for (int i = 0 ; i < text.length() ; i++)
	{
		if (remove.find(text[i]) != std::string::npos)
		{
			text.erase(i, 1);
		}
			
	}
}

std::string getFilePath()
{
	std::string fileName;
	std::cout << "Enter file name: " ;
	std::cin >> fileName;
	std::cout << std::endl;
	std::string filePath = "/Users/admin/Desktop/" + fileName;
	return filePath;
}
