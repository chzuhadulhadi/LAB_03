#pragma once
#ifndef MYARRAY_H
#define MyStack


template <class T>
class MyArray
{
	int size;
	int index;
	T* arr;
public:
	MyArray(int s = 10);
	MyArray(MyArray& myArr);
	~MyArray();
	void addElement(T val);
	T getElement(int i);
	void operator=(const MyArray& myArr);
	T& operator[](const int& i);
};

#endif // !MYARRAY_H

