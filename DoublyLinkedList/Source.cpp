#include "NewDLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string cleanUp(string str)
{
	int i= 0;
	char c;
	string newStr;
	while (str[i])
	{
		c= str[i];
		str[i]= tolower(c);
		i++;
	}
	i= 0;
	return str;
}

int main()
{

	DLinkedList lst1;
	DLinkedList lst2;

	ifstream fin("Text1.in");
	string str;

	while (fin >> str) {
		str = cleanUp(str);
		lst1.insertUniqueOrder(str);
	}
	fin.close();

	fin.open("Text2.in");
	while (fin >> str) {
		str = cleanUp(str);
		lst2.insertUniqueOrder(str);
	}
	fin.close();
	cout << lst1 << "\n";
	cout << lst2 << "\n";

	DLinkedList Merged= lst1.merge(lst2);
	cout << Merged;
}