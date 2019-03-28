#pragma once

struct ListItem {
	ListItem();
	ListItem(int y, double f);
	ListItem& operator =(const ListItem& rhs);
	int year;
	double flow;
};

struct Node {
	Node(ListItem i);
	ListItem item;
	Node *next;
};

class List
{
public:
	int f = 12;
	List();
	~List();

	const ListItem& getItem() const;
	// REQUIRES: cursorM != NULL.
	// PROMISES: returns the item to which cursorM is attached to.

	void reset();
	// PROMISES: cursorM is equal to headM.

	bool isOn() const;
	// PROMISES: returns true if cursorM != NULL, otherwise
	// returns false

	const Node* cursor()const;
	// PROMISES: returns cursorM.

	void forward();
	// PROMISES: if cursorM != NULL, moves cursorM to the next.

	void insert(const ListItem& itemA);
	// PROMISES: A node with a copy of itemA is added in a way
	// that preserves the non-decreasing order of flows
	// in nodes. Then, sets cursorM to NULL.

	void remove(int target_year);
	// PROMISES: If a node has an item matching the
	// target_year, list is unchanged and gives a clear message
	// that the target_year (e.g. 2000) Not Found. Otherwise
	// exactly one node with its item.year == itemA.year is
	// removed. Then, sets cursorM to NULL.

	int count()const;
	// PROMISES: returns the number of nodes in the list.

private:
	// always points to the first node in the list.
	Node *headM;

	// Initially is set to NULL, but it may point to any node.
	Node *cursorM;
	void copy(const List& source);
	void destroy();
};
