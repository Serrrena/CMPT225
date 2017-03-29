#include "Customer.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main(void){
	Customer new1("Zheng",'S',20);
	Customer new2("Zng",'S',20);
	Customer new3("Zeng",'P',20);		
	Customer new4("Zheng",'S',20);
	new1.SetLastName("zpq");
	cout << new1;
	
	//Node pt1(new1.GetLastName(),new2.GetFirstInitial(),new3.GetAcctBalance());
	Node pt1("Zheng",'S',20);
	pt1.printNode();


	
}