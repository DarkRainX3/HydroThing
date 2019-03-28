#include "pch.h"
#include "Hydro.h"
#include "List.h"
#include <iostream>
#include <fstream>
#define underline "\033[4m"
#define CLOSEUNDERLINE "\033[0m"
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
	cout<<"\n<<<<Press Enter to Continue>>>>\n";
	cin.ignore();
}

void Hydro::addData() {
	cout << "Enter the year.\n";
	int year;
	cin >> year;

	cout << "Enter the flow.\n";
	float flow;
	cin >> flow;
	//cout << year << " " << flow;
	if (flowData->isExist(year)) {
		cout << "Error: duplicate data.\n";
		return;
	}
	else {
		ListItem temp = ListItem();
		temp.flow = flow;
		temp.year = year;
		flowData->insert(temp);
		cout << "New record inserted successfully.";
	}
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
		ListItem temp = ListItem();
		temp.flow = b;
		temp.year = a;
		flowData->insert(temp);
		//printElement(a, b);
		//cout << a << " " << b << endl;
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
			display();
			pressEnter();
			break;
		case 2: 
			//cout << "Test2\n";
			addData();
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

void Hydro::display()
{
	flowData->reset();
	cout << setw(10) << underline << "Year" << CLOSEUNDERLINE << setw(8) << underline << "Flow (in billions of cubic meters)" << CLOSEUNDERLINE << endl;
	while (flowData->isOn()) {
		ListItem temp = flowData->getItem();
		printElement(temp.year, temp.flow);
		flowData->forward();
	}
	cout << "The annual average of the flow is: " << average() << " million cubic meters.\n";
	cout << "The median flow is: " << median() << " million cubic meters.";
}

float Hydro::average()
{
	return flowData->avg();
}

float Hydro::median()
{
	return flowData->med();
}

void Hydro::displayHeader() {
	cout << "H-E-F Hydropower Studies - Winter 2019\nProgram: Flow Studies\nVersion : 1.0\nLab section : B01\nProduced by : Your name\n";
	pressEnter();
}
Hydro::Hydro() {
	flowData = new List();
}

Hydro::~Hydro()
{
}

void Hydro::printElement(int year, double flow)
{
	cout <<setw(10) << year << setw(15) << flow << endl;	
}
