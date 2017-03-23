#include "LinkedList.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	
	LinkedList<int> list;
	list.add(14);
	list.add(20);
	list.add(26);
	list.remove(14);
	list.insertAt(2,99);
	list.printList(cout);
	cout << endl;

	LinkedList<int> l2(list);
	l2.printList(cout);
	cout << endl;

	LinkedList<string> list1;
	list1.add("Hello");
	list1.add("World");
	list1.add("!@!");
	list1.remove("World");
	list1.insertAt(1,"HI");
	list1.printList(cout);
	cout << endl;

	LinkedList<string> l3(list1);
	l3.printList(cout);
	cout << endl;

	return 0;
}
