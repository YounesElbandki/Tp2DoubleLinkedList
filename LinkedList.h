#pragma once
using namespace std;
#include "Node.h"

template<typename T>
class LinkedList
{
private:
	Node<T>* first;
	Node<T>* last;
	int length;

public:
	// Default constructor
	LinkedList();
	// Destructor
	~LinkedList();
	// Check if the list is empty	
	bool isEmpty();
	//Getters
	int getLength();
	Node<T>* getFirst();
	Node<T>* getLast();
	Node<T>* get(int);
	// Add a new element to the beginning of the list
	void addFirst(T*);
	// Add a new element to the end of the list
	void addLast(T*);
	// Add a new element at the specified index
	bool add(T*, int);
	// Display the elements in the list
	void display();
	// Remove the first element from the list
	bool removeFirst();
	// Remove the last element from the list
	bool removeLast();
	// Remove the element at the specified index	
	bool remove(int);
	// Check if the list contains the specified element
	bool contains(T*);
	// Remove the first occurrence of the specified element
	bool remove(T*);
};

template<typename T>
LinkedList<T>::LinkedList() {
	first = NULL;
	last = NULL;
	length = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* tmp = first;
	while (first)
	{
		first = first->getNext();
		delete tmp;
		tmp = first;
	}

}

template<typename T>
bool LinkedList<T>::isEmpty() {
	return !first;

}

template<typename T>
int LinkedList<T>::getLength() {
	return length;
}

template<typename T>
Node<T>* LinkedList<T>::getFirst() {
	return first;
}

template<typename T>
Node<T>* LinkedList<T>::getLast() {
	return last;
}

template<typename T>
Node<T>* LinkedList<T>::get(int n) {
	if (n<0 || n>length - 1) {
		cout << " OUT OF RANG";
		return NULL;
	}
	Node<T>* tmp;
	if (n >= (length / 2)) {
		tmp = last;
		for (int i = length - 1; i > n; i--)
			tmp = tmp->getPrevious();
		return tmp;	
	}
	tmp = first;
	for (int i = 0; i < n; i++)
		tmp = tmp->getNext();
	return tmp;
}

template<typename T>
void LinkedList<T>::addFirst(T* entity) {
	Node<T>* newnode = new Node<T>(entity);
	if (isEmpty()) {
		first = newnode;
		last = newnode;
		length++;
	}
	else {
		/*dont us THIS :
		newnode->gatNext() or first->getPrevious
		remember the function are return a pointer so if 
		u didnt assign it to variable it gonna be lost by 
		the end of the function
		*/
		newnode->setNext(first) ;
		first->setPrevious(newnode) ;
		first = newnode;
		length++;
	}
	

}

template<typename T>
void LinkedList<T>::addLast(T* entity) {
	Node<T>* newnode = new Node<T>(entity);
	if (isEmpty()) {
		first = newnode;
		last = newnode;
		length++;
	}
	else {
		newnode->setPrevious(last);
		last->setNext(newnode);
		last = newnode;
		length++;
	}
}

template<typename T>
bool LinkedList<T>::add(T* entity, int n) {
	if (n<0 || n>length) {
		cout << "OUT OF RANG";
		return false;
	}

	if (n == 0) {
		addFirst(entity);
		return true;
	}

	if (n == length) {
		addLast(entity);
		return true;
	}
	Node<T>* newnode = new Node<T>(entity);
	Node<T>* tmp = get(n-1);
	newnode->setNext(tmp->getNext());
	newnode->setPrevious(tmp);
	tmp->getNext()->setPrevious(newnode);
	tmp->setNext(newnode);
	length++;
	
	return true;
}

template<typename T>
void LinkedList<T>::display() {
	Node<T>* tmp = first;
	while (tmp) {
		tmp->getEntity()->display();
		tmp = tmp->getNext();
	}
}

template<typename T>
bool LinkedList<T>::removeFirst() {
	if (isEmpty() ) {
		cout << "THE LIST IS EMPTY";
		return false;
	}
	Node<T>* tmp = first;
	first = first->getNext();
	delete tmp;
	if (!first)
		last = NULL;
	else first->setPrevious(NULL);
	length--;
	return true;
}

template<typename T>
bool LinkedList<T>::removeLast() {
	if (isEmpty()) {
		cout << "THE LIST IS EMPTY";
		return false;
	}
	Node<T>* tmp = last;
	last = last->getPrevious();
	delete tmp;
	if (!last)
		first = NULL;
	else 
		last->setNext(NULL); 
	length--;
	return true;
}

template<typename T>
bool LinkedList<T>::remove(int n) {
	if (n<0 || n>length-1) {
		cout << "OUT OF RANG";
			return false;
	}
	if (n == 0) {
		removeFirst();
		return true;
	}
	if (n == (length-1)) {
		removeLast();
		return true;
	}
	Node<T>* tmp = get(n);
	tmp->getNext()->setPrevious(tmp->getPrevious());
	tmp->getPrevious()->setNext(tmp->getNext());
	delete tmp;
	length--;
	return true;
}

template<typename T>
bool LinkedList<T>::contains(T* entity) {
	Node<T>* tmp = first;
	while (tmp && tmp->getEntity() != entity) {
		tmp = tmp->getNext();
	}
	if (!tmp) {
		cout << "NOT FOUND :(";
			return false;
	}
	cout << "IS FOUND :)";
	return true;
}

template<typename T>
bool LinkedList<T>::remove(T* entity) {
	Node<T>* tmp = first;
	while (tmp && tmp->getEntity() != entity) {
		tmp = tmp->getNext();
	}
	if (!tmp) {
		cout << "OUT OF RANG" << endl;
		return false;
	}
	if (tmp == last) 
		return removeLast();
	
	if (tmp == first) 
		return removeFirst();
	Node<T>* tmpPrev = tmp->getPrevious();
	Node<T>* tmpNext = tmp->getNext();
	tmpNext->setPrevious(tmpPrev);
	tmpPrev->setNext(tmpNext);
	delete tmp;
	length--;
	return true;
}