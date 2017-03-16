#include "LinkedList.h"
#include <iostream>

int main(void) {
	LinkedList<int> list1;
	list1.addHead(1);
	list1.addTail(2);
	list1.addTail(3);
	LinkedList<int> list2;
	list2.addHead(69);
	list2.addTail(420);
	list2.addTail(1337);

	LinkedList<int> list3(list1);
	list1.printList();
	list2.printList();
	list3.printList();
	std::cout << "Finished first set." << std::endl;
	list2 = list1;
	list2.printList();
	std::cout << "2 is now 1" << std::endl;
	list3 = list2;
	list3.printList();
	std::cout << "3 is now 2" << std::endl;
}