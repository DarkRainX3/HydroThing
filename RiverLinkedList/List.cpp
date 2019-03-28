#include "pch.h"
#include "List.h"
#include <iostream>
using namespace std;


List::List()
{
	headM = new Node();
}


List::~List()
{
}

const ListItem & List::getItem() const
{
	// TODO: insert return statement here
	return cursorM->item;
}

void List::reset()
{
}

bool List::isOn() const
{
	if (cursorM != NULL) {
		return true;
	}
	return false;
}


