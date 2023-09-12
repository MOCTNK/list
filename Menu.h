#pragma once
#include <iostream>
#include "Iterator.h"
#include "ReverseIterator.h"
#include "MyList.h"
#include "MyException.h"
using namespace std;

class Menu {
private:
public:
	void start();
	template <typename T> void create(MyList<T> &myList);
	template <typename T> void fillList(MyList<T>& myList) {};
	template <typename T> void randomFillList(MyList<T> &myList) {};
	template <typename T> void writeList(MyList<T>& myList) {};
	template <typename T> void addInList(MyList<T>& myList) {};
	template <typename T> void addInListById(MyList<T>& myList) {};
	template <typename T> void deleteFromList(MyList<T>& myList) {};
	template <typename T> void deleteFromListById(MyList<T>& myList) {};
	template <typename T> void updateValueInList(MyList<T>& myList) {};
	template <typename T> void clearList(MyList<T>& myList) {};
	template <typename T> void isListEmpty(MyList<T>& myList) {};
	template <typename T> void getValueId(MyList<T>& myList) {};
	template <typename T> void searchValue(MyList<T>& myList) {};
	template <typename T> void getValueById(MyList<T>& myList) {};
	template <typename T> void getMenuIterator(MyList<T>& myList) {};
	void menuIterator(Iterator<int>& iterator);
	void menuReverseIterator(ReverseIterator<int>& iterator);
	int getRandomNumber(int min, int max);
	int enterNumber(int min, int max);
	void testBigO();
};

void Menu::start() {
	while (true) {
		bool exit = false;
		int action;
		cout << "Enter type data" << endl;
		cout << "1) int" << endl;
		cout << "2) exit" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);
		MyList<int> myListInt;
		cout << endl;

		switch (action) {
			case 1:
				create<int>(myListInt);
				break;
			case 2:
				exit = true;
				break;
			default:
				std::cout << "error";
				break;
		}

		if (exit) {
			break;
		}
	}
}

template <typename T> void Menu::create(MyList<T> &myList) {
	MyList<T> list = myList;
	int action;
	while (true) {
		bool exit = false;
		cout << "fill the list:" << endl;
		cout << "1) random" << endl;
		cout << "2) add values" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);
		cout << endl;

		switch (action) {
		case 1:
			randomFillList(list);
			exit = true;
			break;
		case 2:
			fillList(list);
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu:" << endl;
		cout << "1) write list" << endl;
		cout << "2) add value" << endl;
		cout << "3) add value by id" << endl;
		cout << "4) delete value" << endl;
		cout << "5) delete value by id" << endl;
		cout << "6) update value by id" << endl;
		cout << "7) clear list" << endl;
		cout << "8) list is empty?" << endl;
		cout << "9) get id by value" << endl;
		cout << "10) get value by id" << endl;
		cout << "11) search value" << endl;
		cout << "12) menu iterator" << endl;
		cout << "13) exit" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 13);
		cout << endl;

		switch (action) {
		case 1:
			writeList(list);
			break;
		case 2:
			addInList(list);
			break;
		case 3:
			addInListById(list);
			break;
		case 4:
			deleteFromList(list);
			break;
		case 5:
			deleteFromListById(list);
			break;
		case 6:
			updateValueInList(list);
			break;
		case 7:
			clearList(list);
			break;
		case 8:
			isListEmpty(list);
			break;
		case 9:
			getValueId(list);
			break;
		case 10:
			getValueById(list);
			break;
		case 11:
			searchValue(list);
			break;
		case 12:
			getMenuIterator(list);
			break;
		case 13:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		cout << endl;
		list.writeList();
		cout << endl;

		if (exit) {
			break;
		}

		cout << endl;
	}
}

template <> void Menu::fillList(MyList<int>& myList) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	cout << "Enter values:" << endl;
	int value;
	for (int i = 0; i < size; i++) {
		value = enterNumber(0, 2147483647);
		myList.add(value);
	}
	myList.writeList();
	cout << endl;
}

template <> void Menu::randomFillList(MyList<int>& myList) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	for (int i = 0; i < size; i++) {
		myList.add(getRandomNumber(1, 100));
	}
	myList.writeList();
	cout << endl;
};

template <> void Menu::writeList(MyList<int> &myList) {
	myList.writeList();
}

template <> void Menu::addInList(MyList<int> &myList) {
	while (true) {
		int value;
		cout << "Enter value:" << endl;
		value = enterNumber(-2147483647, 2147483647);
		myList.add(value);
		break;
	}
}

template <> void Menu::addInListById(MyList<int>& myList) {
	while (true) {
		int value;
		int id;
		cout << "Enter value:" << endl;
		value = enterNumber(-2147483647, 2147483647);
		cout << "Enter id:" << endl;
		id = enterNumber(0, myList.getSize());
		myList.addById(id, value);
		break;
	}
}

template <> void Menu::deleteFromList(MyList<int>& myList) {
	while (true) {
		int value;
		cout << "Enter value:" << endl;
		value = enterNumber(-2147483647, 2147483647);
		myList.deleteValue(value);
		break;
	}
}

template <> void Menu::deleteFromListById(MyList<int>& myList) {
	while (true) {
		int id;
		cout << "Enter id:" << endl;
		id = enterNumber(0, myList.getSize());
		myList.deleteValueById(id);
		break;
	}
}

template <> void Menu::updateValueInList(MyList<int>& myList) {
	while (true) {
		int value;
		int id;
		cout << "Enter value:" << endl;
		value = enterNumber(-2147483647, 2147483647);
		cout << "Enter id:" << endl;
		id = enterNumber(0, myList.getSize());
		myList.updateValueById(id, value);
		break;
	}
}

template <> void Menu::clearList(MyList<int>& myList) {
	myList.clearList();
}

template <> void Menu::isListEmpty(MyList<int>& myList) {
	if (myList.isEmpty()) {
		cout << "List is empty" << endl;
	}
	else {
		cout << "List is not empty" << endl;
	}
}

template <> void Menu::getValueId(MyList<int>& myList) {
	while (true) {
		int value;
		cout << "Enter value:" << endl;
		value = enterNumber(-2147483647, 2147483647);
		cout << "id: " << myList.getId(value) << endl;
		break;
	}
}

template <> void Menu::getValueById(MyList<int>& myList) {
	while (true) {
		int id;
		cout << "Enter id:" << endl;
		id = enterNumber(0, myList.getSize());
		cout << "value: " << myList.getValueById(id) << endl;
		break;
	}
}

template <> void Menu::searchValue(MyList<int>& myList) {
	while (true) {
		int value;
		cout << "Enter value:" << endl;
		value = enterNumber(-2147483647, 2147483647);
		if (myList.searchValue(value)) {
			cout << "The value is in the list" << endl;
		}
		else {
			cout << "The value is not in the list" << endl;
		}
		break;
	}
}

template <> void Menu::getMenuIterator(MyList<int>& myList) {

	while (true) {
		bool exit = false;
		Iterator <int> iter = myList.begin();
		ReverseIterator <int> rIter = myList.rbegin();
		int action;
		cout << "Enter iterator" << endl;
		cout << "1) begin" << endl;
		cout << "2) end" << endl;
		cout << "3) rbegin" << endl;
		cout << "4) rend" << endl;
		cout << "5) exit" << endl;
		cout << "Enter action: " << endl;
		action = enterNumber(1, 5);
		cout << endl;

		switch (action) {
		case 1:
			menuIterator(iter);
			break;
		case 2:
			iter = myList.end();
			menuIterator(iter);
			break;
		case 3:
			menuReverseIterator(rIter);
			break;
		case 4:
			rIter = myList.rend();
			menuReverseIterator(rIter);
			break;
		case 5:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}
}

void Menu::menuIterator(Iterator<int>& iterator) {

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu Iterator" << endl;
		cout << "1) write element" << endl;
		cout << "2) next" << endl;
		cout << "3) prev" << endl;
		cout << "4) write list -->" << endl;
		cout << "5) write list <--" << endl;
		cout << "6) exit" << endl;
		cout << "Enter action: ";
		action = enterNumber(1, 6);
		cout << endl;

		switch (action) {
		case 1:
			cout << "Element: " << * iterator << endl;
			break;
		case 2:
			cout << "next" << endl;
			iterator++;
			break;
		case 3:
			cout << "prev" << endl;
			iterator--;
			break;
		case 4:
			cout << "List: [ ";
			for (int a : iterator) {
				cout << a << " ";
			}
			cout << "]" << endl;
			break;
			break;
		case 5:
			iterator = iterator.end();
			cout << "List: [ ";
			for (int i = 0; i < iterator.getSize(); i++) {
				iterator--;
				cout << *iterator << " ";
			}
			cout << "]" << endl;
			break;
		case 6:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}
		
		cout << endl;
	}
}

void Menu::menuReverseIterator(ReverseIterator<int>& iterator) {
	while (true) {
		bool exit = false;
		int action;
		cout << "Menu Iterator" << endl;
		cout << "1) write element" << endl;
		cout << "2) next" << endl;
		cout << "3) prev" << endl;
		cout << "4) write list -->" << endl;
		cout << "5) write list <--" << endl;
		cout << "6) exit" << endl;
		cout << "Enter action: ";
		action = enterNumber(1, 6);
		cout << endl;

		switch (action) {
		case 1:
			cout << "Element: " << *iterator << endl;
			break;
		case 2:
			cout << "next" << endl;
			iterator++;
			break;
		case 3:
			cout << "prev" << endl;
			iterator--;
			break;
		case 4:
			cout << "List: [ ";
			for (int a : iterator) {
				cout << a << " ";
			}
			cout << "]" << endl;
			break;
			break;
		case 5:
			iterator = iterator.end();
			cout << "List: [ ";
			for (int i = 0; i < iterator.getSize(); i++) {
				iterator--;
				cout << *iterator << " ";
			}
			cout << "]" << endl;
			break;
		case 6:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}
}

int Menu::getRandomNumber(int min, int max) {
	return min + rand() % (max - min + 1);
}

int Menu::enterNumber(int min, int max) {
	int number = min - 1;
	while (true) {
		cout << ">> ";
		cin >> number;
		if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
			break;
		}
		else {
			cout << "Incorrect value!" << endl;
			cin.clear();
			while (cin.get() != '\n') {}
		}
		cout << endl;
	}
	return number;
}

void Menu::testBigO() {
	MyList<int> *list = new MyList<int>[10];
	int s = 1000;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < s; j++) {
			list[i].add(getRandomNumber(1, 100));
		}
		s += 1000;
	}

	s = 1000;

	for (int i = 0; i < 10; i++) {
		int countAdd = 0;
		int countDelete = 0;
		int countSearch = 0;
		for (int j = 0; j < s; j++) {
			list[i].addById(getRandomNumber(0, s), getRandomNumber(1, 100));
			countAdd += list[i].getLastIteration();

			list[i].deleteValueById(getRandomNumber(0, s));
			countDelete += list[i].getLastIteration();

			list[i].searchValue(getRandomNumber(1, 100));
			countSearch += list[i].getLastIteration();
		}

		cout << "Size: " << s << endl;
		cout << "1.39*log2(n)=" << 1.39 * (log((double)s) / log(2.0)) << endl;
		cout << "Count add: " << countAdd / s << endl;
		cout << "Count delete: " << countDelete / s << endl;
		cout << "Count search: " << countSearch / s << endl << endl;
		s += 1000;
	}

	delete[] list;
}