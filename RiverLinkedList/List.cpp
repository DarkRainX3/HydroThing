#include "pch.h"
#include "List.h"
#include <iostream>
using namespace std;


List::List()
{
	//headM = new Node();
	headM = NULL;
}


List::~List()
{
}

const ListItem & List::getItem() const
{
	if (cursorM!=NULL)
		return cursorM->item;
	else {
		ListItem *temp = new ListItem();
		cout << "Unable to get item, cursor is null!";
		return *temp;
	}
}

void List::reset()
{
	cursorM = headM;
}

bool List::isOn() const
{
	if (cursorM != NULL) {
		return true;
	}
	return false;
}

const Node * List::cursor() const
{
	return cursorM;
}

void List::forward()
{
	if (cursorM != NULL) {
		cursorM = cursorM->next;
	}
	else {
		cout << "Cursor is null, now resetting.";
		reset();
	}
}

int List::count() const
{
	Node *temp = headM;
	int counter = 0;
	while (temp != NULL) {
		temp = temp->next;
		counter++;
	}
	return counter;
}


