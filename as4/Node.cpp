#include "Node.h"


Node::Node():left_(NULL),right_(NULL),parent_(NULL){}
Node::Node(Customer item){
	this->current_.SetLastName(item.GetLastName());
	this->current_.SetFirstInitial(item.GetFirstInitial());
	this->current_.SetAcctBalance(item.GetAcctBalance());
	this->left_ = NULL;
	this->right_= NULL;
	this->parent_ = NULL;
}
Node::Node(string name,char first,int acctb){
	this->current_.SetLastName(name);
	this->current_.SetFirstInitial(first);
	this->current_.SetAcctBalance(acctb);
	this->left_ = NULL;
	this->right_= NULL;
	this->parent_ = NULL;
}
Node::~Node(){
	
	this->left_ = NULL;
	this->right_= NULL;
	this->parent_ = NULL;
}
void Node::printNode(){
	cout<< current_;
}
Customer& Node::GetCustomer(){
	return current_;
}
string Node::GetLast(){
	return current_.GetLastName();
}
char Node::GetFirst(){
	return current_.GetFirstInitial();
}
int Node::GetAcct(){
	return current_.GetAcctBalance();
}