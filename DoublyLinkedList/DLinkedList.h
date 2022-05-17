#pragma once

#ifndef DLINKLIST_H
#define DLINKLIST_H
#include <iostream>

using namespace std;

template <class T>
class DLinkedList {

	friend ostream &operator<<(ostream &out, const DLinkedList<T> &rhs) {
		DNode *curr = rhs.header->next;
		while (curr != rhs.header) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:

	class DNode {
	public:
		DNode *next;
		DNode *prev;
		T data;

		DNode(T val = T()) {
			data = val;
			next = prev = this;
		}

	};

	//create an empty list
	DLinkedList() {
		//create the header
		header = new DNode();
	}

	//add method
	DNode *add(T item) {
		//add a new node and return a 
		//pointer to this node
		DNode *newNode = new DNode(item);
		newNode->prev = header;
		newNode->next = header->next;
		header->next->prev = newNode;
		header->next = newNode;
		return newNode;
	}

	void insertOrder(T item) {
		DNode *newDNode = new DNode(item);
		// new node containing the new data
		DNode *temp = header->next;
		// temp header node
		while (temp->data <= newDNode->data && temp != header)
		{
			temp = temp->next;
		}
		// loop to know where to insert the new data
		if (temp->next == header && temp->data <= newDNode->data)
		{
			// checks if the data is less than the final node
			newDNode->next = temp->next;
			// inserts node before the last value
			newDNode->prev = temp;
			temp->next->prev = newDNode;
			temp->next = newDNode;
		}
		else if (temp == header && temp->data >= newDNode->data)
		{
			// checks if the data is greater than the final node
			newDNode->next = temp;
			// inserts node after the last value
			newDNode->prev = temp->prev;
			temp->prev->next = newDNode;
			temp->prev = newDNode;
			header = newDNode;
			// reassign header node
		}
		else
		{
			// inserts node for all other cases
			newDNode->next = temp;
			newDNode->prev = temp->prev;
			temp->prev->next = newDNode;
			temp->prev = newDNode;
		}
	}

	//O(n)
	bool insertOrderUnique(T item)
	{
		DNode *newDNode = new DNode(item);
		// new node containing the new data
		DNode *temp = header->next;
		// temp header node
		while (temp->data <= newDNode->data && temp != header)
		{
			if (temp->data == newDNode->data) { return false; }
			temp = temp->next;
		}
		insertOrder(newDNode->data);
		return true;
	}


	//The logic seems sound but the program seems to be getting caught in an infinite loop
	//but not one that adds more functions on top, because it's not dumping the core
	//O(n*m)
	DLinkedList merge(DLinkedList rhs)
	{
		DLinkedList result;
		
		DNode* temp = header;
		while(temp != NULL)
		{
		  result.insertOrder(temp->data);
		  temp = temp->next;
		  cout << "Next\n";
		}
		
		temp = rhs.header->next;
		while(temp != NULL)
		{
		  rhs.insertOrderUnique(temp->data);
		  temp= temp->next;
		}
		return result;
	}

private:
	DNode *header;
};


#endif
