// test.cpp
// Driver program for testing linked list copies and destructor.
#include "node.h"
#include "linkedlist.h"
#include <iostream>
using namespace std;


int main () {
  LinkedList list;
	list.add(1);
	list.add(2);
	list.add(3);

	cout << "Print first list -- expecting {1, 2, 3}." << endl;
	list.printList();
	cout << endl << endl;

	cout  << "Make a copy of the list" << endl << endl;
	LinkedList secondList(list);
    
	list.add(4);
	list.add(5);
	list.add(6);

	cout << endl << "Add items and print first list -- expecting {1, 2, 3, 4, 5, 6}." << endl;
	list.printList();
	cout << endl << endl;

	cout << "Print second list.  If it was deep copied should be {1, 2, 3}." << endl;
	secondList.printList();
	cout << endl << endl;
	secondList.~LinkedList();

	cout << "Print second list.  after dest." << endl;
	secondList.printList();
	cout << endl;
}
