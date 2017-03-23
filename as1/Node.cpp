/*
 * Node.cpp
 *
 */

#include "Node.h"
#include <iostream>
using namespace std;

Node:: Node(){
	data = 0;
	next = NULL;
}
Node:: Node( int a ){
	data = a;
	next = NULL;
}
Node::~Node(){
	data = 0;
	next = NULL;
}
int Node:: getdata(){
	return data;
}
void Node:: changedata(int k){
	data = k;
}

// TO DO:: Fill in.
