#pragma once

struct ListItem {
	int year;
	double flow;
};

struct Node {
	ListItem item;
	Node *next;
};

class List
{
public:
	List();
	List(List& l);
	~List();
	List& operator=(const List &l);
	float avg();
	float med();
	void swap(float *xp, float *yp);
	void bubbleSort(float arr[], int n);
	void printArray(float arr[], int size);
	bool isExist(int year);
	// PROMISES: returns true if year already exist in list.

	const ListItem& getItem() const;
	// REQUIRES: cursorM != NULL.
	// PROMISES: returns the item to which cursorM is attached to.

	void reset();
	// PROMISES: cursorM is equal to headM.

	bool isOn() const;
	// PROMISES: returns true if cursorM != NULL, otherwise
	// returns false

	const Node* cursor()const; //const after a function means function cannot make changes to member variables
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

