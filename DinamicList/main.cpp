#include <iostream>
#include "DoubleList.h"

using namespace std;
int main()
{
	DoubleList<int> dl;
	cout << (bool)dl<<endl;

	dl.pushBack(5);
	dl.pushFront(4);
	dl.pushFront(2);
	dl.insert(1, 0);
	cout << dl.size() << endl;
	cout << (int)dl << endl;
	dl.pushBack(6);
	dl.insert(3, 2);
	dl.insert(7, 6);
	dl.insert(8, 7);

	cout << (bool)dl<<endl;

	for (int i = 0; i < 8; i++)
	{
		cout << dl[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		dl.remove((int)dl-1);
	}
	return 0;
}