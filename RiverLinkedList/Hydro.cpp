#include "pch.h"
#include "Hydro.h"
#include "List.h"
#include <iostream>
#include <fstream>
using namespace std;

int Hydro::main() {
	
	displayHeader();
	numOfData = readData();
	//cout << numOfData << "\n";
	menu();
	//addData();
	return 0;
}

void Hydro::pressEnter() {
	cout<<"<<<<Press Enter to Continue>>>>";
	cin.ignore();
}

void Hydro::addData() {
	cout << "Enter the year.\n";
	int year;
	cin >> year;

	cout << "Enter the flow.\n";
	float flow;
	cin >> flow;
	cout << year << " " << flow;
	//TODO
}

int Hydro::readData() {
	int counter = 0;
	const char *fname = "flow.txt";
	ifstream inFile;
	inFile.open(fname);
	if (!inFile) {
		cout << "Error: cannot open the file" << endl;
		exit(1);
	}
	while (!inFile.eof()) {
		int a;
		float b;
		inFile >> a >> b;
		cout << a << " " << b << endl;
		counter++;
		//TODO 
	}
	inFile.close();
	return counter;
}

void Hydro::menu()
{
	while (true) {
		cout << "Please select on the following operations\n\
		1. Display flow list, average and median\n\
		2. Add data.\n\
		3. Save data into the file\n\
		4. Remove data\n\
		5. Quit\n\
		Enter your choice(1, 2, 3, 4, or 5) : \n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: cout << "Test1\n";//TODO;
			pressEnter();
			break;
		case 2: cout << "Test2\n";
			pressEnter();
			break;
		case 3: cout << "Test3\n";
			pressEnter();
			break;
		case 4: cout << "Test4\n";
			pressEnter();
			break;
		case 5: exit(1);
		}
		cin.ignore();
	}
}

void Hydro::displayHeader() {
	cout << "H-E-F Hydropower Studies – Winter 2019\nProgram: Flow Studies\nVersion : 1.0\nLab section : B01\nProduced by : Your name\n";
	pressEnter();
}
Hydro::Hydro() {
	flowData = new List();
}

Hydro::~Hydro()
{
}
