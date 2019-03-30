#pragma once
#include "List.h"
#include <iomanip>
class Hydro
{
public:
	Hydro();
	~Hydro();

	void printElement(int year, double flow);

	int main();
	void displayHeader();
	void addData(List &l);
	int readData();
	void menu();
	void display(List &l);
	void removeData();
	float average(List &l);
	float median(List &l);
	void saveData();
	void pressEnter();
private:
	List flowData;
	int numOfData = 0;
};

