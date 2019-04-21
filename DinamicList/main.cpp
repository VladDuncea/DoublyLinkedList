#include <iostream>
#include "DoubleList.h"

int main()
{
	DoubleList<int> dl;
	
	dl.pushBack(5);
	dl.pushFront(4);
	dl.pushFront(2);
	dl.insert(1, 0);
	dl.pushBack(6);
	dl.insert(3, 2);
	dl.insert(7, 6);
	dl.insert(8, 7);
	for (int i = 0; i < 8; i++)
	{
		std::cout << dl[i] << " ";
	}
	return 0;
}