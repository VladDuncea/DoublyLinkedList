#pragma once
#include <iostream>

template<class Type>
class Node
{
	Node<Type> * privPrev, *privNext;
	Type privData;
public:
	Node();
	Node(Type data);
	~Node();

	//Getter function for next node
	Node<Type> * next() const;
	//Setter function for next node
	void next(Node<Type> * n);

	//Getter function for prev node
	Node<Type> * prev() const;
	//Setter function for prev node
	void prev(Node<Type> * n);

	//Getter function for data
	Type data() const;
	Type& data_ref();

	//Setter function for data
	void data(Type x);
};

template<class Type>
Node<Type>::Node()
{
	privPrev = privNext = NULL;
}

template<class Type>
Node<Type>::Node(Type data)
{
	privNext = privPrev = NULL;
	privData = data;
}

template<class Type>
Node<Type>::~Node()
{
}

template<class Type>
Node<Type>* Node<Type>::next() const
{
	return privNext;
}

template<class Type>
void Node<Type>::next(Node<Type>* n)
{
	privNext = n;
}

template<class Type>
Node<Type>* Node<Type>::prev() const
{
	return privPrev;
}

template<class Type>
void Node<Type>::prev(Node<Type>* n)
{
	privPrev = n;
}

template<class Type>
Type Node<Type>::data() const
{
	return privData;
}

template<class Type>
Type& Node<Type>::data_ref()
{
	return privData;
}

template<class Type>
void Node<Type>::data(Type x)
{
	data = x;
}
