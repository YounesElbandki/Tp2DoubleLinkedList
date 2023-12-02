#pragma once
template<typename T>
class Node
{

private:
	T* entity;
	Node<T>* next;
	Node<T>* previous;
public:
	Node(T*);
	~Node();
	T* getEntity();
	Node<T>* getNext();
	Node<T>* getPrevious();
	void setNext(Node<T>*);
	void setPrevious(Node<T>*);
};

template<typename T>
Node<T>::Node(T* e) {
	entity = e;
	next = NULL;
	previous = NULL;
}

template<typename T>
Node<T>::~Node() {
	delete entity;
}

template<typename T>
void Node<T>::setNext(Node<T>* next) {
	this->next = next;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* previous) {
	this->previous = previous;
}

template<typename T>
T* Node<T>::getEntity() {
	return entity;
}

template<typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template<typename T>
Node<T>* Node<T>::getPrevious() {
	return previous;
}

