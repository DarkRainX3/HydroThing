#include "pch.h"
#include "List.h"
#include <iostream>
using namespace std;


List::List()
{
	//headM = new Node();
	headM = 0;
}

List::List(List & l)
{
	copy(l);
}


List::~List()
{
	destroy();
}

List& List::operator=(const List & l)
{
	if (this != &l) {
		destroy();
		copy(l);
	}
	return *this;
}



float List::avg()
{
	Node *temp = headM;
	float total = 0.0;
	while (temp != NULL) {
		total += temp->item.flow;
		temp = temp->next;
	}
	return total/count();
}

float List::med()
{
	int nodes = count();
	float *array =new float[nodes];
	//cout << nodes << endl;
	Node *temp = headM;
	for (int i = 0; i < nodes; i++) {
		float tempp = temp->item.flow;
		array[i] = tempp;
		//cout << array[i]<<" "<<endl;
		temp = temp->next;
	}
	bubbleSort(array, nodes);
	//printArray(array, nodes);
	if (nodes % 2 != 0)
		return (double)array[nodes / 2];

	return (double)(array[(nodes - 1) / 2] + array[nodes / 2]) / 2.0;
}



void List::swap(float * xp, float * yp)
{
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void List::bubbleSort(float arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void List::printArray(float arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%.3f ", arr[i]);
	printf("\n");
}

bool List::isExist(int year)
{
	Node *temp = headM;
	while (temp != NULL) {
		if (year == temp->item.year)
			return true;
		temp = temp->next;
	}
	return false;
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
	if (cursorM != nullptr) {
		cursorM = cursorM->next;
	}
	else {
		cout << "Cursor is null, now resetting.";
		reset();
	}
}

void List::insert(const ListItem & itemA)
{
	if (isExist(itemA.year)) {
		//cout << "The entry for this year already exists!";
		return;
	}
	Node *new_node = new Node;
	new_node->item = itemA;

	if (headM == 0 || itemA.year < headM->item.year) {
		new_node->next = headM;
		headM = new_node;
	}
	else {
		Node *before = headM;
		Node *after = headM->next;
		while (after != 0 && itemA.year > after->item.year) {
			before = after;
			after = after->next;
		}
		new_node->next = after;
		before->next = new_node;
	}
	cursorM = NULL;
}

void List::remove(int target_year)
{
	if (headM == 0 || target_year < headM->item.year)
		return;

	Node *doomed_node = 0;

	if (target_year == headM->item.year) {
		doomed_node = headM;
		headM = headM->next;
	}
	else {
		Node *before = headM;
		Node *maybe_doomed = headM->next;
		while (maybe_doomed != 0 && target_year > maybe_doomed->item.year) {
			before = maybe_doomed;
			maybe_doomed = maybe_doomed->next;
		}
		if (maybe_doomed != 0 && maybe_doomed->item.year == target_year) {
			before->next = maybe_doomed->next;
			//delete(maybe_doomed);
		}
	}
	//delete(doomed_node);
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

void List::copy(const List & source)
{
	Node *cursor = source.headM;
	//Node *temp2 = headM;
	Node *temp = new Node();
	headM = temp;
	if (cursor != NULL) {
		headM->item = cursor->item;
	}
	else {
		headM = 0;
		//cout << "List::copy was called.\n";
		return;
	}
	Node *prev = headM;
	cursor = cursor->next;
	while (cursor != NULL) {
		Node *a = new Node();
		a->item = cursor->item;
		prev->next = a;
		prev = a;
		cursor = cursor->next;
	}

	//cout << "List::copy was called.\n";
}

void List::destroy()
{
	Node *temp = headM;
	Node *temp2 = headM;
	while (temp != NULL) {
		temp = temp->next;
		delete(temp2);
		temp2 = temp;
	}
	//cout << "List::destroy was called List was destroyed.\n";
	headM = 0;
}


