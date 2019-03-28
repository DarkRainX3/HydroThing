#pragma once
#include "List.h"
class Hydro
{
public:
	Hydro();
	~Hydro();
	int main();
	void displayHeader();
	void addData();
	int readData();
	void menu();
	void display();
	void removeData();
	float average();
	float median();
	void saveData();
	void pressEnter();
private:
	List *flowData;
	int numOfData = 0;
};

