// RiverLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "List.h"
#include "Hydro.h"
using namespace std;


//List *flowData;
//int numOfData = 0;
//
//void displayHeader() {
//	cout << "H-E-F Hydropower Studies – Winter 2019\nProgram: Flow Studies\nVersion : 1.0\nLab section : B 01\nProduced by : Your name\n<<<<Press Enter to Continue>>>>";
//	cin.get();
//}
//
//void addData() {
//	cout << "Enter the year.\n";
//	int year;
//	cin >> year;
//
//	cout << "Enter the flow.\n";
//	float flow;
//	cin >> flow;
//	cout << year << " " << flow;
//}
//
//int readData() {
//	int counter = 0;
//	const char *fname = "flow.txt";
//	ifstream inFile;
//	inFile.open(fname);
//	if (!inFile) {
//		cout << "Error: cannot open the file" << endl;
//			exit(1);
//	}
//	while (!inFile.eof()) {
//		int a;
//		float b;
//		inFile >> a >> b;
//		cout << a<<" "<< b <<endl;
//		counter++;
//	}
//	inFile.close();
//	return counter;
//}
//void pressEnter() {
//	cout << "\n<<<<Press Enter to Continue>>>>\n";
//	do {
//		
//	} while (std::cin.get() != '\n');
//	std::cin.ignore();
//}

int main()
{
	//while (true) {
	//	pressEnter();
	//}
	/*Test t1, t2; 
	t2 = t1; Assignment operator called
	Test t3 = t1; Copy constructor called*/
	
	Hydro *h = new Hydro();
	h->main();
	//flowData = new List();
	//List *a = new List();
	//List *b = new List();
	//a = b;
	//delete(a);
	//cout << b->f;
	//displayHeader();
	//numOfData = readData();
	//cout << numOfData;
	//addData();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
