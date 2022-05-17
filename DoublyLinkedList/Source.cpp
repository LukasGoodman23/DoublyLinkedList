#include "DLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string cleanUp(string str);

int main() {

	DLinkedList<string> lst1;
	DLinkedList<string> lst2;

	ifstream fin("Text1.in");
	string str;

	while (fin >> str) {
		str = cleanUp(str);
		lst1.insertOrderUnique(str);
	}
	fin.close();

	fin.open("Text2.in");
	while (fin >> str) {
		str = cleanUp(str);
		lst2.insertOrderUnique(str);
	}
	fin.close();

	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;

	return 0;
}

bool isNotLow(string str)
{
	int i= 0;
	if (str[i] < 123 || str[i] > 96) { return true; }
	else { return false; }
}

//O(n)
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