
#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
	Node();
	Node(string name,char first,int acctb);
	void printNode();
private:
	Customer current_;
	Node* left_;
	Node* right_;
	Node* parent_;
};

#endif /* NODE_H_ */
