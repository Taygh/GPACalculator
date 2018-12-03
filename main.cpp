#include <iostream>
#include <fstream>
#include <string>
#include "dialogue.h"
using namespace std;

//Purpose: To calculate an overall GPA for a quarter based student using
//pre-existing files for credits/grades

//Input: file for grades, file for credits, user input to exit program

//Processing: read grades/credits per line into two seperate stacks, reverse stacks
//so that they print in order, calculate overall GPA

//Output: prompts for file inputs, list of classes with grades/credits, overall GPA
//at end of list, prompt to exit

//Example:
//
//Enter a file location for credits: credits.txt
//Enter a file location for grades: grades.txt
//
//Grade: 4.0
//Credits: 5.0
//
//Grade: 3.7 
//Credits: 3
//
//Grade: 3.7
//Credits: 1
//
//Overall GPA: 3.87...
//Press any key and enter to exit
//(user exits)

int main()
{
	double tempLine; //used to hold values for credit or grade when reading files
	double perGrade; //used to calculate grade*credits per class
	double totalC; //total credits overall
	double totalNum; //total number of grade*credits overall to calculate overall GPA
	double final; //final overall GPA
	string cInput; //name of credits file
	string gInput; //name of grades file
	ifstream cOpen; //used for reading in credits from file 
	ifstream gOpen; //used for reading in grades from file
	NumStack creditStack; //stack to hold total credits
	NumStack gradeStack; //stack to hold total grades
	NumStack creditStackR; //stack to reorder credits correctly (reverse the reveresed stack)
	NumStack gradeStackR; //stack to reorder grades correctly (reverse the reveresed stack)
	int i; //tracks total credit input
	int x; //tracks total grade inputs

	//get files
	cout << "Enter a file location for credits: ";
	cin >> cInput;
	cout << "Enter a file location for grades: ";
	cin >> gInput;

	//read in files to stacks and ensure they are in correct order
	cOpen.open(cInput);

	i = 0;
	x = 0;

	if (!cOpen.is_open())
	{
		return 0;
	}

	while (cOpen >> tempLine)
	{
		creditStackR.push(tempLine);
		i++;
	}

	creditStack.copyReverse(creditStackR);

	gOpen.open(gInput);

	while (gOpen >> tempLine)
	{
		gradeStackR.push(tempLine);
		x++;
	}

	gradeStack.copyReverse(gradeStackR);

	totalC = 0;
	totalNum = 0;

	//print out each grade with associated credits and calculate total GPA
	while ((i != 0) && (x != 0))
	{
		cout << "Grade: " << gradeStack.peak() << endl;
		cout << "Credits: " << creditStack.peak() << endl;
		totalC += creditStack.peak();
		perGrade = gradeStack.pop() * creditStack.pop();
		totalNum += perGrade;
		final = totalNum / totalC;
		i--;
		x--;
		cout << endl;
	}

	//print out total/overall GPA
	cout << "Overall GPA: " << final << endl;

	//end program
	cout << "Press any key and enter to exit" << endl;
	cin >> gInput;
	cin.ignore();
	return 0;
}