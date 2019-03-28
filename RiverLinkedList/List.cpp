#include "pch.h"
#include "List.h"


List::List()
{
	
	headM(ListItem(0, 0.0););
}


List::~List()
{
}

const ListItem & List::getItem() const
{
	// TODO: insert return statement here
}

void List::reset()
{
}

bool List::isOn() const
{
	if (cursor != 0) {
		return true;
	}
	return false;
}

ListItem::ListItem(int y, double f)
{
	year = y;
	flow = f;
}

ListItem & ListItem::operator=(const ListItem & rhs)
{
	// TODO: insert return statement here
}

Node::Node(ListItem i)
{
	item = i;
}
