#include "pch.h"
#include "Hydro.h"
#include "List.h"
#include <iostream>
#include <fstream>
using namespace std;

int Hydro::main() {
	
	displayHeader();
	numOfData = readData();
	cout << numOfData;
	addData();
	return 0;
}

void Hydro::pressEnter() {
	cout<<"<<<<Press Enter to Continue>>>>";
	getchar();
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
	inFile.open(fname);	if (!inFile) {
		cout << "Error: cannot open the file" << endl;
		exit(1);
	}	while (!inFile.eof()) {
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
