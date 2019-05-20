#include <iostream>
#include "DoubleList.h"

using namespace std;

class A
{
public:
	int m_x, m_y;

	A(int x = 0, int y = 0)
	{
		m_x = x;
		m_y = y;
	}
	void afis()
	{
		cout << m_x << " " << m_y << "\n";
	}
};


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

	DoubleList<int>::iterator it=dl.begin();
	cout << *it;

	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		dl.remove((int)dl-1);
	}

	cout << endl << endl;
	DoubleList<A> dla;
 	dla.pushFront(A());
	dla.pushBack(A(1, 7));
	dla[0].afis();
	dla[0].m_x = 7;
	dla[0].afis();
	DoubleList<A>::iterator ita = dla.begin();
	ita->afis();
	ita++;
	ita->afis();
	(*ita).m_x = 5;
	ita->afis();
	return 0;
}