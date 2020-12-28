#pragma once
#include<iostream>
template<class T>
struct TLink {
	T val;
	TLink<T>* pNext;
};

template <class T>
class Stack 
{
	TLink<T>* pFirst;
public:
	Stack();
	Stack(const Stack<T>& m);
	~Stack();
	Stack<T>& operator =(const Stack<T>& m);
	int operator == (const Stack<T>& s);
	int operator != (const Stack<T>& s);
	bool Empty();
	//bool Full();
	void Push(T a);
	void Clear_Stack();
	T Pop();
	T Top();
	int size();
};
template <class T>
int Stack<T>::size()
{
	TLink<T> _pFirst = pFirst;
	int k;
	while (_pFirst != NULL)
	{
		k++;
	}
	return k;
}

template <class T>
Stack<T>::Stack()
{
	pFirst = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& m)
{
	if (m.pFirst != NULL)
	{
		TLink<T>* prev = new TLink<T>;
		TLink<T>* tmp = m.pFirst;
		prev->val = tmp->val;
		pFirst = prev;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			TLink<T>* p = new TLink<T>;
			p->val = tmp->val;
			prev->pNext = p;
			prev = p;
			tmp = tmp->pNext;
		}
		prev->pNext = NULL;
	}
	else
		pFirst = NULL;
}

template<class T>
Stack<T>::~Stack()
{
	while (pFirst != NULL)
	{
		TLink<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		//TLink<T>* tmp = pFirst->pNext;
		//delete pFirst;
		//pFirst = tmp;
	}
}

template <class T>
Stack<T>& Stack<T>:: operator =(const Stack<T>& m)
{
	if (m.pFirst != NULL)
	{
		while (pFirst != NULL)
		{
			TLink<T>* tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
		TLink<T>* prev = new TLink<T>;
		TLink<T>* tmp = m.pFirst;
		pFirst = prev;
		prev->val = m.pFirst->val;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			TLink<T>* p = new TLink<T>;
			p->val = tmp->val;
			prev->pNext = p;
			prev = p;
			tmp = tmp->pNext;
		}
		prev->pNext = NULL;
	}
	else
		pFirst = NULL;
	return (*this);
}

template <class T>
bool Stack<T> ::Empty()
{
	return pFirst == NULL;
}

/*template <class T>
bool Stack<T> ::Full()
{
	if (Size == MaxSize)
	{
		return true;
	}
	return false;
}*/

template <class T>
void Stack<T> ::Push(T elem)
{
	TLink<T>* tmp = new TLink<T>;
	tmp->val = elem;
	tmp->pNext = pFirst;
	pFirst = tmp;
}

template <class T>
T Stack<T> ::Pop()
{
	if (pFirst == NULL)
		throw NULL;
	T elem = pFirst->val;
	TLink<T>* tmp = pFirst;
	pFirst = tmp->pNext;
	delete tmp;
	return elem;
}

template <class T>
T Stack<T> ::Top()
{
	if (pFirst == NULL)
		throw NULL;
	return pFirst->val;
}

template <class T>
int Stack<T> :: operator ==(const Stack<T>& m)
{
	if (this != &m)
	{
		TLink<T>* tmp_1 = m.pFirst;
		TLink<T>* tmp_2 = pFirst;
		while (true)
		{
			if (tmp_1 == NULL && tmp_2 == NULL)
				break;
			if (tmp_1->val != tmp_2->val)
				return false;
			tmp_1 = tmp_1->pNext;
			tmp_2 = tmp_2->pNext;
		}
	}
	return true;
}

template <class T>
int Stack<T> :: operator !=(const Stack<T>& m)
{
	return !(*this == m);
}

template <class T>
void Stack<T>::Clear_Stack()
{
	while (pFirst != NULL)
	{
		TLink<T>* tmp = pFirst->pNext;
		delete pFirst;
		pFirst = tmp;
	}
}