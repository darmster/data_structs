/*
Assignment 4
Dr. Ghyam
CS1
Darmis Hoskins
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	//Declare variables step 1
	//        ifstream inFile;
	ofstream outFile;

	double average = 0.0;
	double totAvg = 0.0;
	double totUnit = 0.0;
	string name;
	string id;
	char grade;
	int unit, point; 
	double total = 0;
	int myUnits = 0;

	//prompt for text file
	cout << "Enter a file name: ";
	getline(cin,name);

	ifstream inFile(name.c_str(), ios::in);

	// commented out inFile.open() while trying to find working input solution
	//inFile.open("assign4.txt");
	outFile.open("myResults.txt");

	//check for file
	if (!inFile)
	{
		cout << "No file exists " << endl;
		return 1;
	}


	// Display heading
	outFile << "Name" << setw(48) << "ID#" << setw(15) << "Units " << setw(6) << "GPA " <<  endl;
	cout << "Name" << setw(48) << "ID#" << setw(15) << "Units " << setw(6) << "GPA " <<  endl;
	outFile << setfill('-');
	cout << setfill('-');
	outFile << setw(80) << '-' <<  endl;
	cout << setw(80) << '-' <<  endl;

	// start reading file
	getline(inFile,name);
	outFile << setfill(' ');
	cout << setfill(' ');

	while (!inFile.eof()) {
		inFile >> id;

		inFile >> grade;
		while (grade != '*')
		{
			// process grade
			switch (grade)
			{
			case 'A':
			case 'a':
				point = 4;
				break;
			case 'B':
			case 'b':
				point = 3;
				break;
			case 'C':
			case 'c':
				point = 2;
				break;
			case 'D':
			case 'd':
				point = 1;
				break;
			case 'F':
			case 'f':
				point = 0;
				break;
			default:
				point = -1;
			}

			inFile >> unit;
			if ( point >= 0 && point < 5){
				total += (point * unit);
				myUnits += unit;
				average = (total/myUnits);	
				totUnit += unit;
			}

			inFile >> grade;

		}

		//print to outFile and monitor

		totAvg += (myUnits * average);
		outFile << setw(48) << left << name;
		cout << setw(48) << left << name;
		outFile << setw(15) << id;
		cout << setw(15) << id;
		outFile << setw(6) << myUnits;
		cout << setw(6) << myUnits;
		outFile << fixed << showpoint;
		cout << fixed << showpoint;
		outFile << setprecision(2);
		cout << setprecision(2);
		outFile << setw(6) << average << " ";
		cout << setw(6) << average << " ";
		outFile << endl;
		cout << endl;
		myUnits = 0;
		total = 0;
		inFile.ignore(100,'\n');

		//commented out getline() while looking for solution dh
		getline(inFile,name);
	}

	outFile << setfill('-');
	cout << setfill('-');
	outFile << setw(80) << '-' <<  endl;
	cout << setw(80) << '-' <<  endl;
	outFile << "The average GPA for all entered grades is "<< totAvg/totUnit << endl;	
	cout << "The average GPA for all entered grades is "<< totAvg/totUnit << endl;	


	inFile.close();
	outFile.close();
	system("pause");
	cin.get();
	cin.get();
	cin.get();
	return 0;
}
