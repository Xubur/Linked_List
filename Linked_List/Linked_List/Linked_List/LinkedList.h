#pragma once
#include <cstdlib>

template <class Item> class LinkedList;

template <class Item>
class Node {
public:
	const Item& getData() const { return data; };			// returns the data held in this node
	Node<Item>* getNext() const { return next; };			// return the next node that this points to
private:
	Item data;												// type of data held in Node
	Node<Item>* next;										// next item that this Node is pointing to
	friend class LinkedList<Item>;
};

template <class Item>
class LinkedList {
public:
	LinkedList();							// empty constructor
	LinkedList(LinkedList<Item>&);		// copy costructor
	~LinkedList();											// dee structor  ...haha.

	LinkedList<Item>& operator=(LinkedList<Item>&);						// assignment operator

	bool isEmpty() const;									// is this empty?

	const Item& getHeadData() const;							// return front element
	void addHead(const Item&);			// add to front of list
	void removeHead();										// remove front item list

	void addTail(const Item&);			// add node to end of list

	Node<Item>*  getHead() const { return head; };			// return address of head node
	Node<Item>*  getTail() const { return tail; };			// return address of tail node

	void printList() const;

private:
	Node<Item>* head;										// pointer to the head node of the list
	Node<Item>* tail;										// pointer to the tail node of the list
};

template <class Item>
LinkedList<Item>::LinkedList() {
	head = NULL;
	tail = NULL;
}

//copy constructor personal implementation
template <class Item>
LinkedList<Item>::LinkedList(LinkedList<Item>& listToCopy) {
	if (listToCopy.isEmpty()) {
		head = tail = NULL;
	}
	else {
		Node<Item>* tempNode = new Node<Item>;
		head = tempNode;
		head->data = listToCopy.getHeadData(); //Is this going to make any problems because getHeadData is constant data type?
		for (Node<Item>* index = listToCopy.head; index != NULL; index = index->next) {
			addTail(index->data);
		}

	}

}

template<class Item>
LinkedList<Item>::~LinkedList() {
	std::cout << "Our head is: " << getHeadData();
	while (!isEmpty())
		removeHead();
}

template<class Item>
LinkedList<Item>& LinkedList<Item>::operator=(LinkedList<Item>& otherList) {
	if (this != &otherList) {
		while (head != NULL) {
			removeHead();
		}
		addHead(otherList.getHeadData());
		for (Node<Item>* index = head; index != NULL; index = index->getNext()) {
			addTail(index->getData());
		}
	}
	return *this;
}

template <class Item>
bool LinkedList<Item>::isEmpty() const {
	return (head == NULL);
}

template <class Item>
const Item& LinkedList<Item>::getHeadData() const {
	return head->data;
}

template <class Item>
void LinkedList<Item>::addHead(const Item& newData) {
	Node<Item>* newNode = new Node<Item>;
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
	if (tail == NULL)			// if there is no tail,
		tail = newNode;		// set  the tail equal to the head

}

template <class Item>
void LinkedList<Item>::removeHead() {
	Node<Item>* oldHead = head;
	head = oldHead->next;
	delete oldHead;
};

template <class Item>
void LinkedList<Item>::addTail(const Item& newData) {
	//Construct the new tail node
	Node<Item>* newNode = new Node<Item>;
	newNode->data = newData;
	newNode->next = NULL;		//This is the tail. There is nothing to point to
	if (tail == NULL) {	//If we have an empty list, assign everything to this one node
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;	//The original tail now points to the new tail
		tail = tail->next;		//The tail of the linked list is now newNode
	}
};

template <class Item>
void LinkedList<Item>::printList() const {

	if (head == NULL)
		std::cout << "oh crap. head is null." << std::endl;
	for (Node<Item>* index = head; index != NULL; index = index->getNext()) {
		std::cout << index->getData() << std::endl;
	}
	std::cout << "We all done" << std::endl;
};