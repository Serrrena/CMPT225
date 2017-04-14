#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include "Node.h"
#include "BSTree.h"

using namespace std;

int main( void ){
	BSTree b;
	b.insert("Joe",'J',123);
	b.insert("Joe",'A',123);
	b.insert("Joe",'C',123);
	b.insert("Joe",'Y',123);
	b.insert("Doe",'J',123);
	b.insert("Doe",'J',123);
	b.insert("Doe",'K',123);
	b.insert("Can",'A',123);
	b.insert("Can",'F',123);
	b.insert("Can",'S',123);
	b.insert("Can",'D',123);
	b.insert("Oscar",'X',123);
	b.insert("Oscar",'D',123);
	b.insert("Oscar",'F',123);
	b.insert("Oscar",'Z',123);
	b.insert("Ken",'A',123);
	b.insert("Ken",'W',123);
	b.insert("Ken",'Y',123);
	b.insert("Ken",'C',123);
	b.insert("Sam",'X',123);
	b.insert("Sam",'V',123);
	b.insert("Bob",'C',123);
	b.insert("Bob",'A',123);
	b.insert("Bob",'D',123);
	b.insert("Arlen",'D',123);
	b.insert("Arlen",'A',123);
	b.insert("Arlen",'B',123);
	b.insert("Arlen",'K',123);
	b.insert("Ethan",'Z',123);
	b.insert("Ethan",'J',123);
	b.insert("Ethan",'F',123);
	b.insert("Ethan",'D',123);
	b.insert("Fogg",'D',123);
	b.insert("Fogg",'A',123);
	b.insert("Fogg",'E',123);
	b.inOrderPrint();
	cout << "---------" << endl;
	b.search("Joe",'A');
	b.search("Doe",'K');
	b.search("Oscar",'X');
	b.search("Fogg",'E');
	b.search("Fogg",'A');
	b.search("Bob",'A');
	b.search("Ken",'A');
	cout << "----------" << endl;
	b.search("Fogg",'C');
	b.search("Joe",'C');
	b.search("Sam",'A');
	b.search("Bob",'K');
	b.search("Ken",'B');
	cout << "----------" << endl;
	vector<Customer> v = b.rangeSearch("Arlen",'A',"Ethan",'Z');
	for( vector<Customer>::iterator i = v.begin(); i != v.end(); i++ ){
		cout << *i << endl;
	}
	cout << "----------" << endl;
	cout << b.GetCurrentNode("Ken",'A')->GetParent()->GetCustomer() << endl;

	return 0;
}
