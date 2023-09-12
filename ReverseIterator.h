#pragma once
#include <iostream>
#include "Iterator.h"
using namespace std;

template <class T> class ReverseIterator {
private:
	int id;
	int size;
	T* data;
public:
	ReverseIterator(T* data, int size);
	ReverseIterator(Iterator<T>& iterator) {};
	ReverseIterator& operator++();
	ReverseIterator operator++(int);
	ReverseIterator& operator--();
	ReverseIterator operator--(int);
	bool operator==(ReverseIterator other) const;
	bool operator!=(ReverseIterator other) const;
	T operator*() const;
	ReverseIterator begin();
	ReverseIterator end();
	int getSize() { return size; };
};

template <class T> ReverseIterator<T>::ReverseIterator(T* data, int size) {
	this->size = size;
	this->data = data;
};

template <class T> ReverseIterator<T>& ReverseIterator<T>::operator++() {
	if (id > -1) {
		id--;
	}
	return *this;
}

template <class T> ReverseIterator<T> ReverseIterator<T>::operator++(int) {
	if (id > -1) {
		id--;
	}
	return *this;
}

template <class T> ReverseIterator<T>& ReverseIterator<T>::operator--() {
	if (id < size) {
		id++;
	}
	return *this;
}

template <class T> ReverseIterator<T> ReverseIterator<T>::operator--(int) {
	if (id < size - 1) {
		id++;
	}
	return *this;
}

template <class T> bool ReverseIterator<T>::operator==(ReverseIterator other) const {
	return data[id] == other.data[other.id];
}

template <class T> bool ReverseIterator<T>::operator!=(ReverseIterator other) const {
	return !(*this == other);
}

template <class T> T ReverseIterator<T>::operator*() const {
	return data[id];
}

template <class T> ReverseIterator<T> ReverseIterator<T>::begin() {
	id = size - 1;
	return *this;
}

template <class T> ReverseIterator<T> ReverseIterator<T>::end() {
	id = -1;
	return *this;
}