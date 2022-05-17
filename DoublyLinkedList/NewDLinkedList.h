#pragma once

#ifndef NEWDLINKLIST_H
#define NEWDLINKLIST_H
#include <iostream>
#include <string>

using namespace std;

class DLinkedList
{
	friend ostream &operator<<(ostream &out, const DLinkedList &rhs)
	{
		DNode *curr= rhs.header;
		while (curr != nullptr)
		{
			out << curr->data<< " ";
			curr= curr->next;
		}
		return out;
	}

public:
	class DNode
	{
	public:
		DNode *next;
		DNode *previous;
		string data;

		template <class T>
		DNode(T val= T())
		{
			data= val;
			next= previous= nullptr;
		}
	};

	DLinkedList()
	{
		header= nullptr;
	}

	DLinkedList(string item)
	{
		header= new DNode(item);
	}

	DNode *getHeader() { return header; }

	void insertFront(string item)
	{
		DNode *newNode= new DNode(item);
		if (header == nullptr)
		{
			header= newNode;
		}

		newNode->next= header;
		header->previous= newNode;
		header= newNode;
	}

	void insertBack(string item)
	{

		DNode *newNode= new DNode(item);
		if (header == nullptr)
		{
			header= newNode;
		}

		DNode *tempNode= header;
		while (tempNode->next != nullptr)
		{
			tempNode= tempNode->next;
		}
		//cout << tempNode->data;
		tempNode->next= newNode;
		newNode->previous= tempNode;
	}

	void insertUniqueOrder(string item)
	{
		DNode *newNode= new DNode(item);

		if (header == nullptr)
		{
			header= newNode;
		}

		DNode *tempNode= header;
		while (tempNode->data < newNode->data && tempNode->next != nullptr)
		{
			tempNode= tempNode->next;
		}
		if (tempNode->data != item)
		{
			if (tempNode == header)
			{
				insertFront(item);
			}
			else if (tempNode->next == nullptr)
			{
				insertBack(item);
			}
			else
			{
				newNode->next= tempNode;
				newNode->previous= tempNode->previous;
				tempNode->previous->next= newNode;
				tempNode->previous= newNode;
			}
		}
		

	}

	DLinkedList merge(DLinkedList rhs)
	{
		DLinkedList result;
		DNode *tempNode= header;
		while (tempNode != nullptr)
		{
			result.insertUniqueOrder(tempNode->data);
			tempNode= tempNode->next;
		}

		tempNode= rhs.getHeader();
		while (tempNode != nullptr)
		{
			result.insertUniqueOrder(tempNode->data);
			tempNode= tempNode->next;
		}
		return result;
	}

private:
	DNode *header;
};


#endif