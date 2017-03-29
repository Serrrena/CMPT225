#include <iostream>
#include "Node.h"
using namespace std;

Node::Node():left_(NULL),right_(NULL),parent_(NULL){}

Node::Node(string name,char first,int acctb){
	this->current_.SetLastName(name);
	this->current_.SetFirstInitial(first);
	this->current_.SetAcctBalance(acctb);
	this->left_ = NULL;
	this->right_= NULL;
	this->parent_ = NULL;
}
void Node::printNode(){
	cout<< current_;
}