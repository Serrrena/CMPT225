#include <iostream>
#include "Node.h"
#include "ATMQueue.h"
using namespace std;
ATMQueue::ATMQueue(){
	front = new Node;
	back = front;
	number = 0;
}
ATMQueue::ATMQueue(int a){
	front = new Node(a);
	back = front;
	number = 1;
}
ATMQueue::~ATMQueue(){
	Node*nxt;
	while(front){
		nxt = front->next;
		front->~Node();
		front = nxt;
	}
}
int ATMQueue::size(){
	return number;
}
bool ATMQueue::ifempty(){
	if(number == 0){
		return true;
	}
	else{
		return false;
	}
}
void ATMQueue::enqueue(int b){
	Node *new_customer = new Node(b);
	if (new_customer){
		if (number == 0){
		front = new_customer;
		}
		back->next = new_customer;
		back = new_customer;
		number++;
	}		
	else{
		cout << "error to enqueue" << endl;
		//return 0;
	}
}
void ATMQueue::dequeue(){
	if( not ifempty()){
		Node *prevcustomer = front;
		front = front->next;
		delete prevcustomer;
		number--;
	}
	
}
int ATMQueue::headdata(){
	if (not ifempty()){
		return front->data;
	}
	else{
		return 0;
	}
	
}
int ATMQueue::taildata(){
	if (not ifempty()){
		return back->data;
	}
	else{
		return 0;
	}
	
}
// TO DO:: Fill in.
