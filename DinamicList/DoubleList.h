#pragma once
#include "Node.h"
#include <iostream>
#include <new>

template<class Type>
class DoubleList
{
	Node<Type> * privFirst;
	Node<Type> * privLast;

	//Empty function
	void privEmpty();

	Node<Type> * privGetNodeByPoz(int poz);
	Node<Type> * privGetNodeByValue(const Type & data);

public:
	
	DoubleList();
	//Copy constructor
	DoubleList(DoubleList<Type> &dl);

	~DoubleList();
	
	void pushFront(const Type & data);
	void pushBack(const Type & data);

	Type popFront();
	Type popBack();

	void insert(const Type & data,int poz);
	void remove(const Type & data);

	//Operator
	DoubleList<Type> & operator=(DoubleList<Type> & dl);
	Type operator[](const int i);
};

template<class Type>
void DoubleList<Type>::privEmpty()
{
	while (privFirst != NULL)
	{
		Node<Type> * aux = privFirst->next();
		delete privFirst;
		privFirst = aux;
	}
	privFirst = privLast = NULL;
}

template<class Type>
Node<Type>* DoubleList<Type>::privGetNodeByPoz(int poz)
{
	//TODO throw out of bounds
	Node<Type> *n = privFirst;
	int cpoz = 0;
	while (cpoz < poz)
	{
		if (n == NULL)
			return NULL;
		n = n->next();
		cpoz++;
	}
	return n;
}

template<class Type>
Node<Type>* DoubleList<Type>::privGetNodeByValue(const Type & data)
{
	//TODO throw node not existing
	Node<Type> *n = privFirst;
	while (n->data() != data)
	{
		if (n == NULL)
			return NULL;
		n = n->next();
	}
	return n;
}

template<class Type>
DoubleList<Type>::DoubleList()
{
	privFirst = privLast = NULL;
}

template<class Type>
DoubleList<Type>::DoubleList(DoubleList<Type>& dl)
{
	privFirst = NULL;
	privLast = NULL;

	//Use the = operator
	*this = dl;
}

template<class Type>
DoubleList<Type>::~DoubleList()
{
	privEmpty();
}

template<class Type>
void DoubleList<Type>::pushFront(const Type & data)
{
	Node<Type> *n;
	try {
		n = new Node<Type>(data);
	}
	catch (std::bad_alloc & e) {
		throw e;
	}
	//First node in list
	if (privFirst == NULL)
	{
		privFirst = privLast = n;
	}

	//Link node to prev first elem
	n->next(privFirst);
	privFirst->prev(n);
	privFirst = n;
}

template<class Type>
void DoubleList<Type>::pushBack(const Type & data)
{
	Node<Type> *n;
	try {
		n = new Node<Type>(data);
	}
	catch (std::bad_alloc & e) {
		throw e;
	}
	//First node in list
	if (privFirst == NULL)
	{
		privFirst = privLast = n;
	}
	n->prev(privLast);
	privLast->next(n);
	privLast = n;
}

template<class Type>
Type DoubleList<Type>::popFront()
{
	//Save the data to return it later
	Type data = privFirst->data();
	//Save node to delete later
	Node<Type> * toDel = privFirst;
	//Set next node as new front
	privFirst = privFirst->next();
	privFirst->prev(NULL);
	//Delete node and return
	delete toDel;
	return data;
}

template<class Type>
Type DoubleList<Type>::popBack()
{
	//Save the data to return it later
	Type data = privLast->data();
	//Save node to delete later
	Node<Type> * toDel = privLast;
	//Set next node as new front
	privLast = privLast->prev();
	privLast->next(NULL);
	//Delete node and return
	delete toDel;
	return data;
}

template<class Type>
void DoubleList<Type>::insert(const Type & data, int poz)
{
	//Insert on pozition 0
	if (poz == 0)
	{
		pushFront(data);
		return;
	}
	//Get the node in front of the new node
	Node<Type> * prev = privGetNodeByPoz(poz - 1);
	//We are out of the list, insert on last position
	if (prev == privLast||prev==NULL)
	{
		pushBack(data);
	}
	//Insert on this position
	else
	{
		//Create the node
		Node<Type> * n = new Node<Type>(data);
		//Get the node next to the added one
		Node<Type> *next = prev->next();

		//Create all links
		prev->next(n);
		n->prev(prev);
		n->next(next);
		next->prev(n);
	}
}

template<class Type>
void DoubleList<Type>::remove(const Type & data)
{
	//get the node by its value
	Node<Type> * n = privGetNodeByValue(data);
	//Check if the node exists
	if (n == NULL)
		return;
	//The node is the first
	if (n == privFirst)
	{
		privFirst = privFirst->next();
		privFirst->prev(NULL);
		delete n;
		return;
	}
	//The node is the last
	if (n == privLast)
	{
		privLast = privLast->prev();
		privLast->next(NULL);
		delete n;
		return;
	}

	//The node has a prev and a next
	n->prev()->next(n->next());
	n->next()->prev(n->prev());
	delete n;
}

template<class Type>
DoubleList<Type>& DoubleList<Type>::operator=(DoubleList<Type>& dl)
{
	//empty list first
	privEmpty();

	//TODO use pushBack()

	Node<Type> * aux = dl.privFirst;
	Node<Type> * prev = NULL;
	Node<Type> * n = NULL;
	while (aux != NULL)
	{
		//Create a new node to duplicate
		n = new Node<Type>;
		//If this is the first node update
		if (privFirst == NULL)
			privFirst = n;
		//Copy data
		n->data(aux->data());
		//Link to prev node
		n->prev(prev);
		//Connect the prev node to this one
		if (prev != NULL)
			prev->next(n);

		//Iterate
		aux = aux->next();
		prev = n;
	}
	n->next(NULL);
	privLast = n;

	return *this;
}

template<class Type>
Type DoubleList<Type>::operator[](const int i)
{
	Node<Type> *n = privGetNodeByPoz(i);
	if (n == NULL)
		return NULL;
	return n->data();
}
