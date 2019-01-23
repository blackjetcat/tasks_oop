#pragma once

//#define STACK_H

#include <cassert> // assert
#include <iostream>
#include <iomanip> // setw

template<typename T> struct data
{
	T val;
	data<T> * next;
};


template <typename T> class Stack
{
	data<T> * info;
	int len;
	data<T> * top;
private:
public:
	Stack();
	Stack(const Stack<T> &);
	~Stack();

	void push(const T &); // ok
	T pop(); // ok
	void printStack(); // ok
	int getStackSize() const; // ok
	T *get_top() const; // ok
};



template <typename T>
Stack<T>::Stack()
{
	top = nullptr;
	info = nullptr;
	len = 0;
}


template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack)
{
	data<T> * b = otherStack.top; 
	while (b) {
		this.push(b);
		b = b->next;
	}
}

template <typename T>
Stack<T>::~Stack()
{
	while (info)
	{
		data<T> * del = info;
		info = info->next;
		delete del;
	}
}

template <class T> void Stack<T>::push(const T &a)
{
	len++;
	info = (data<T>*)new data<T>;
	info->val = a;
	//std::cout << "\nadded" << a;
	if (!top) {
		top = info;
		info->next = nullptr;
	}
	else
	{
		info->next = top;
		top = info;
	}
};


template <typename T>
inline T Stack<T>::pop()
{
	if (!len) return T();
		len--;
		T to_return = info->val;
		data<T>* to_del = top;
		top = top->next;
		delete to_del;
		return to_return;
}
 


//   1  2  3   top
// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	data<T> * b = top;
	while (b)
	{
		std::cout << "\n" << b->val;
		b = b->next;
	}
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return len;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::get_top() const
{
	return top->val;
}

template <class Q> 
Q square(Q val) {
	return val * val;
}