#pragma once
#include <iostream>
using namespace std;

template <class T> class Iterator {
private:
	int id;
	int size;
	T* data;
public:
	Iterator(T* data, int size);
	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);
	bool operator==(Iterator other) const;
	bool operator!=(Iterator other) const;
	T operator*() const;
	Iterator begin();
	Iterator end();
	int getSize() { return size; };
};

template <class T> Iterator<T>::Iterator(T* data, int size) {
	this->size = size;
	this->data = data;
};

template <class T> Iterator<T> &Iterator<T>::operator++() {
	if (id < size) {
		id++;
	}
	return *this;
}

template <class T> Iterator<T> Iterator<T>::operator++(int) {
	if (id < size - 1) {
		id++;
	}
	return *this;
}

template <class T> Iterator<T>& Iterator<T>::operator--() {
	if (id > 0) {
		id--;
	}
	return *this;
}

template <class T> Iterator<T> Iterator<T>::operator--(int) {
	if (id > 0) {
		id--;
	}
	return *this;
}

template <class T> bool Iterator<T>::operator==(Iterator other) const { 
	return data[id] == other.data[other.id]; 
}

template <class T> bool Iterator<T>::operator!=(Iterator other) const { 
	return !(*this == other); 
}

template <class T> T Iterator<T>::operator*() const { 
	return data[id]; 
}

template <class T> Iterator<T> Iterator<T>::begin() {
	id = 0;
	return *this;
}

template <class T> Iterator<T> Iterator<T>::end() {
	id = size;
	return *this;
}