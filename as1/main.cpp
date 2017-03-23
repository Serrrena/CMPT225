#include "ATM.h"
#include "Node.h"
#include "ATMQueue.h"
#include "Customer.h"
#include "iostream"
using namespace std;

int main(){
	// test Node
	Node n1 = Node();
	Node n2 = Node(2);
	cout << n1.getdata() << endl;
	cout << n2.getdata() << endl;
	n1.changedata(5);
	cout << n1.getdata() << endl;
	/*// test ATMQueue
	ATMQueue *Atmque1 = new ATMQueue();
	cout<< Atmque1->headdata() << endl;
	Atmque1->enqueue(1);
	Atmque1->enqueue(2);
	//Atmque1->enqueue(10);
	//Atmque1->dequeue();	
	cout<< "front data : " << Atmque1->headdata() << " back data : "<<  Atmque1->taildata() << endl;
	cout << "size of atmque is " << Atmque1->size() << endl;
	if (Atmque1->ifempty()){
		cout << " que is empty " <<endl;
	}
	else{
		cout << "que is not empty " <<endl;
	}*/
	// test ATM
	//ATM *atm1 = new ATM();
	ATM *Atm[4]; //= new ATM();
	int i,leftcustomer,k;
	for (k = 0; k < 4;k++){  
		Atm[k] = new ATM();	 
    } 	
	Atm[0]->ArrivalCustomer(2);
	Atm[0]->ArrivalCustomer(5);
	Atm[1]->ArrivalCustomer(1);
	Atm[2]->ArrivalCustomer(2);
	Atm[3]->ArrivalCustomer(4);
	Atm[0]->ProcessNewCustomer();
	if( Atm[0]->ProcessCurrentCustomer()){
		cout << "one customer finish" <<endl;
	}
	else{
		cout << "customer not finish" <<endl;
	}
	if( Atm[0]->ProcessCurrentCustomer()){
		cout << "one customer finish" <<endl;
	}
	else{
		cout << "customer not finish" <<endl;
	}
	//Atm[0]->ProcessNewCustomer();
	//cout <<"total number of customer is " ;
	cout <<Atm[0]->AtmQueueSize() <<endl;
	delete Atm[4];
	//cout<< "front data : " << Atmque1->headdata() <<endl ;
	return 0;
}