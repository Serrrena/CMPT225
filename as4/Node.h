
#ifndef NODE_H_
#define NODE_H_
#include "Customer.h"
#include <iostream>
using namespace std;
//class BSTree;
class Node {
friend class BSTree;
public:
	Node();
	Node(Customer item);
	Node(string name,char first,int acctb);
	~Node();
	void printNode();	
	Customer& GetCustomer();
	string GetLast();
	char GetFirst();
	int GetAcct();
private:
	Customer current_;
	Node* left_;
	Node* right_;
	Node* parent_;
};

#endif /* NODE_H_ */
