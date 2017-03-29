#include <iostream>
#include "ADT.h"

using namespace std;

Node::Node( int n ){
	data = n;
	next = NULL;
	cout << "Node Create" << endl;
}

Node::~Node(){}

StackLL::StackLL():head(NULL){
	cout << "LL Create" << endl;

}

StackLL::~StackLL(){
	Node *node = head;
	while( node ){
		Node *next = node->next;
		delete node;
		node = next;
	}
	cout << "LL Delete" << endl;

}

void StackLL::Push( int n ){
	// Node *node = new Node(n);
	// if ( head == NULL ){
	// 	cout << "e" << endl;
	// 	head = node;
	// 	return;
	// }

	// Node *temp = head;
	// while( temp->next ){
	// 	temp = temp->next;
	// }

	// temp->next = node;
	Node *node = new Node(n);
	if ( head == NULL ){
		head = node;
		return;
	}
	node->next = head;
	head = node;
}

int StackLL::Pop(){
	if( head == NULL ){
		return 0;
	} 
	Node *top = head;
	head = head->next;
	int result = top->data;
	delete top;
	return result; 
}

void StackLL::Print(){
	Node *node = head;
	while( node ){
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

