#include <iostream>
using namespace std;

class Node{
friend class ListStack;
public:
	Node(){
		data = 0;
		next = NULL;
	}
	Node(int a){
		data = a;
		next = NULL;
	}
private:
	int data;
	Node *next;
};

class ListStack{
public:
	ListStack(int k){
		stack = new Node(k);
		stack->next = NULL;
	}
	void push(int k){
		Node *node = new Node(k);
		node->next = stack;
		stack  = node;
	}
	void pop(){
		Node *top = stack;
		stack = stack->next;
		delete top;
	}
	void printstack(){
		cout << stack->data << endl;
	}
private:
	Node *stack;
};

int main(void){
	ListStack a = ListStack(5);
	a.printstack();
	a.push(3);
	a.printstack();
	a.push(7);
	a.push(6);
	a.push(10);
	a.pop();
	a.printstack();
	
}