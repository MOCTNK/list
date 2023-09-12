#pragma once
#include <iostream>
#include "Iterator.h"
#include "ReverseIterator.h"
using namespace std;

template <class T> class MyList {
public:
	MyList();
	MyList(MyList &list);
	~MyList();
	int getSize();
	int getCapacity();
	void add(T value);
	void addById(int id, T value);
	void deleteValue(T value);
	void deleteValueById(int id);
	void updateValueById(int id, T value);
	void clearList();
	int getId(T value);
	T getValueById(int id);
	bool searchValue(T value);
	bool isEmpty();
	void writeList();
	int getLastIteration();
	Iterator<T> begin();
	Iterator<T> end();
	ReverseIterator<T> rbegin();
	ReverseIterator<T> rend();
private:
	int iterations = 0;
	T* data = NULL;
	int size = 0;
	int capacity = 0;
	void increaseSize();
	void reductionSize();
};


template <class T> MyList<T>::MyList() {
	capacity = 2;
	data = new T[capacity];
}

template <class T> MyList<T>::MyList(MyList &list) {
	if (data != NULL) {
		delete[] data;
	}
	capacity = list.getCapacity();
	size = list.getSize();
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = list.getValueById(i);
	}
}

template <class T> MyList<T>::~MyList() {
	delete[] data;
}

template <class T> int MyList<T>::getSize() {
	return size;
}

template <class T> int MyList<T>::getCapacity() {
	return capacity;
}

template <class T> void MyList<T>::add(T value) {
	if (size == capacity) {
		increaseSize();
	}
	data[size] = value;
	size++;
}

template <class T> void MyList<T>::addById(int id, T value) {
	int t = 0;
	if (id >= 0 and id <= size) {
		if (size == capacity) {
			increaseSize();
		}

		for (int i = size - 1; i >= id; i--) {
			data[i + 1] = data[i];
			t++;
		}
		data[id] = value;
		size++;
		iterations = t;
	}
	else {
		cout << "Error! id is out of range" << endl;
	}
}

template <class T> void MyList<T>::deleteValueById(int id) {
	int t = 0;
	if (id >= 0 and id < size) {
		for (int i = id; i < size; i++) {
			data[i] = data[i + 1];
			t++;
		}
		size--;

		if (size == capacity / 2) {
			reductionSize();
		}

		iterations = t;
	}
	else {
		cout << "Error! id is out of range" << endl;
	}
}

template <class T> void MyList<T>::updateValueById(int id, T value) {
	if (id >= 0 and id < size) {
		data[id] = value;
	}
	else {
		cout << "Error! id is out of range (0-" << size - 1 << ")" << endl;
	}
}

template <class T> void MyList<T>::clearList() {
	if (!isEmpty()) {
		delete[] data;
		size = 0;
		capacity = 2;
		data = new T[capacity];
	}
}

template <class T> void MyList<T>::deleteValue(T value) {
	if (!isEmpty()) {
		int id = getId(value);
		if (id > 0) {
			deleteValueById(id);
		}
	}
}

template <class T> int MyList<T>::getId(T value) {
	int id = -1;
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			id = i;
			break;
		}
	}
	return id;
}

template <class T> T MyList<T>::getValueById(int id) {
	return data[id];
}

template <class T> bool MyList<T>::searchValue(T value) {
	int t = 0;
	bool search = false;
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			search = true;
			break;
		}
		t++;
	}
	iterations = t;
	return search;
}

template <class T> bool MyList<T>::isEmpty() { 
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> void MyList<T>::writeList() {
	Iterator <T> iter = begin();
	cout << "List: [ ";
	for (T a : iter) {
		cout << a << " ";
	}
	cout << "] size:" << size << " capacity:" << capacity << endl;
}

template <class T> Iterator<T> MyList<T>::begin() {
	Iterator <T> iter(data, size);
	return iter;
}

template <class T> Iterator<T> MyList<T>::end() {
	Iterator <T> iter(data, size);
	iter = iter.end();
	return iter;
}

template <class T> int MyList<T>::getLastIteration() {
	return iterations;
}

template <class T> ReverseIterator<T> MyList<T>::rbegin() {
	ReverseIterator <T> iter(data, size);
	return iter;
}

template <class T> ReverseIterator<T> MyList<T>::rend() {
	ReverseIterator <T> iter(data, size);
	iter = iter.end();
	return iter;
}

template <class T> void MyList<T>::increaseSize() {
	T* oldData = data;
	capacity *= 2;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = oldData[i];
	}
	delete[] oldData;
}

template <class T> void MyList<T>::reductionSize() {
	if (capacity > 2) {
		T* oldData = data;
		capacity /= 2;
		data = new T[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = oldData[i];
		}
		delete[] oldData;
	}
}