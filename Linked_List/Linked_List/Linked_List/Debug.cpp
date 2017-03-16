#include "LinkedList.h"
#include <iostream>

int main(void) {
	LinkedList<int> list1;
	list1.addHead(1);
	list1.addTail(2);
	list1.addTail(3);
	LinkedList<int> list2(list1);
	list1.printList();
	list2.printList();
}