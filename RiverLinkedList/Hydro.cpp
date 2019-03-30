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
	List copy1;
	copy1 = flowData;
	cout << "insert these 2 entries 2012 459.99 and 2013 2000.34" << endl;
	addData(copy1);
	addData(copy1);
	List copy2 = copy1;
	copy2.remove(1922);
	copy2.remove(2003);
	copy2.remove(2001);

	cout << "\n values in copy2 are: \n";
	display(copy2);
	cout << "\n values in copy1 are: \n";
	display(copy1);
	cout << "\n values in flowData are: \n";
	display(flowData);

	return 0;
}

void Hydro::pressEnter() {
	cout<<"\n<<<<Press Enter to Continue>>>>\n";
	do {
	} while (cin.get() != '\n');
}

void Hydro::addData(List& l) {
	cout << "Enter the year.\n";
	int year;
	cin >> year;

	cout << "Enter the flow.\n";
	float flow;
	cin >> flow;
	//cout << year << " " << flow;
	if (l.isExist(year)) {
		cout << "Error: duplicate data.\n";
		return;
	}
	else {
		numOfData++;
		ListItem temp = ListItem();
		temp.flow = flow;
		temp.year = year;
		l.insert(temp);
		cout << "New record inserted successfully.\n";
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
		flowData.insert(temp);
		//printElement(a, b);
		//cout << a << " " << b << endl;
		counter++;
	}
	inFile.close();
	return counter;
}

void Hydro::menu()
{
	bool running = true;
	while (running) {
		cout << "Please select on the following operations\n\
		1. Display flow list, average and median\n\
		2. Add data.\n\
		3. Save data into the file\n\
		4. Remove data\n\
		5. Quit\n\
		Enter your choice(1, 2, 3, 4, or 5) : \n";
		int choice;
		bool valid = true;
		try {
			/*choice = (int)cin.get()-48;*/
			cin >> choice;
			while (cin.fail() == true) {
				valid = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
			choice = 0;
		}

		if (!valid)
			choice =0;
		switch (choice) {
		case 1:
			display(flowData);
			pressEnter();
			break;
		case 2: 
			addData(flowData);
			pressEnter();
			break;
		case 3:
			saveData();
			cout << "Data saved.\n";
			pressEnter();
			break;
		case 4:
			removeData();
			pressEnter();
			break;
		case 5:
			cout << "Program terminated successfully.\n";
			running = false;
			/*exit(1);*/
			break;
		default:
			cout << "Please pick a number between 1-5.\n";
			pressEnter();
			break;
		}
		if(valid)
			cin.get();
	}
}

void Hydro::display(List &l)
{
	l.reset();
	cout << setw(10) << underline << "Year" << CLOSEUNDERLINE << setw(8) << underline << "Flow (in billions of cubic meters)" << CLOSEUNDERLINE << " " << endl;
	while (l.isOn()) {
		ListItem temp = l.getItem();
		printElement(temp.year, temp.flow);
		l.forward();
	}
	cout << "The annual average of the flow is: " << average(l) << " million cubic meters.\n";
	cout << "The median flow is: " << median(l) << " million cubic meters.\n";
}

void Hydro::removeData()
{
	int year;
	cout << "Please enter the year you wish to remove.\n";
	cin >> year;
	if (flowData.isExist(year)) {
		flowData.remove(year);
		numOfData--;
		cout << "Successfully deleted year: " << year << endl;
	}
	else {
		cout << "Error, no data for that year exists.\n";
		return;
	}
}

float Hydro::average(List& l)
{
	return l.avg();
}

float Hydro::median(List &l)
{
	return l.med();
}

void Hydro::saveData()
{
	const char *fname = "flow.txt";
	ofstream outFile;
	outFile.open(fname);
	if (!outFile) {
		cout << "Error opening file! Now exiting\n";
		exit(1);
	}
	flowData.reset();
	const Node *temp = flowData.cursor();
	while (temp != NULL) {
		int a;
		float b;
		a = temp->item.year;
		b = temp->item.flow;
		outFile << setw(10) << a << setw(15) << b << endl;
		temp = temp->next;
	}
	outFile.close();
}

void Hydro::displayHeader() {
	cout << "H-E-F Hydropower Studies - Winter 2019\nProgram: Flow Studies\nVersion : 1.0\nLab section : B01\nProduced by : Waley Chen\n";
	pressEnter();
}
Hydro::Hydro() {
	flowData = List();
}

Hydro::~Hydro()
{
}

void Hydro::printElement(int year, double flow)
{
	cout <<setw(10) << year << setw(15) << flow << endl;	
}
