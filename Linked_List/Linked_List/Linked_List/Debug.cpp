#include "LinkedList.h"
#include <iostream>

int main(void) {
	LinkedList<int> list1;
	LinkedList<int> list2;

	list2.addHead(18);
	list2.addTail(12345678);

	std::cout << "List1: " << std::endl;
	list1.printList();
	std::cout << "List2: " << std::endl;
	list2.printList();

	list2 = list1;

	std::cout << "List2 is now list1: " << std::endl;
	list2.printList();
}