#include "Customer.h"
#include "Node.h"
#include "BSTree.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){

	BSTree b;
	b.insert("Joe",'J',123);
	b.insert("Joe",'A',123);
	b.insert("Joe",'Y',123);
	b.insert("Joe",'C',123);
	b.insert("Doe",'J',123);
	b.insert("Arlen",'B',123);
	// b.insert("Arlen",'K',123);
	// b.insert("Ethan",'Z',123);
	// b.insert("Ethan",'J',123);
	// b.insert("Ethan",'F',123);
	// b.insert("Doe",'J',123);
	// b.insert("Doe",'L',123);
	// b.insert("Doe",'K',123);
	// b.insert("Can",'A',123);
	// b.insert("Can",'F',123);
	// b.insert("Can",'S',123);
	// b.insert("Can",'D',123);
	// b.insert("Oscar",'X',123);
	// b.insert("Oscar",'D',123);
	b.insert("Oscar",'F',123);
	b.insert("Oscar",'Z',123);
	b.insert("Ken",'B',123);
	b.insert("Ken",'A',123);
	b.insert("Ken",'Y',123);
	b.insert("Ken",'C',123);
	b.insert("Sam",'X',123);
	b.insert("Sam",'V',123);
	b.insert("Bob",'C',123);
	// b.insert("Bob",'A',123);
	// b.insert("Bob",'D',123);
	// b.insert("Arlen",'D',123);
	// b.insert("Arlen",'A',123);
	b.insert("Arlen",'B',123);
	b.insert("Arlen",'K',123);
	b.insert("Ethan",'Z',123);
	// b.insert("Ethan",'J',123);
	// b.insert("Ethan",'F',123);
	// b.insert("Ethan",'D',123);
	// b.insert("Fogg",'D',123);
	b.insert("Fogg",'A',123);
	b.insert("Fogg",'E',123);
	b.inOrderPrint();
	b.rangeSearch("Doe",'J',"M",'A');
	
	// BSTree t(b);

	// t.insert("Alexander",'G',3031);
	// t.insert("Webb",'O', 6791);
	// t.insert("Mueller",'U', 1971);
	// t.inOrderPrint();
	// // b.insert("Stokes",'A', 2794);
	// b.insert("Berger",'U', 5766);
	// b.insert("Garrison",'A', 1074);
	// b.insert("Franco",'E', 2367);
	// b.insert("Peters",'J', 4828);
	// b.insert("Stokes",'Q', 8398);
	// b.insert("Harrell",'O', 2832);
	//b.remove("Peters",'J');
	// b.remove("Alexander",'G');
	 cout << endl;
	

	// b.remove("Joe",'A');
	// b.remove("Joe",'C');
	// b.remove("Joe",'J');
	// b.remove("Joe",'Y');
	// b.remove("Doe",'K');
	// b.remove("Doe",'J');
	// b.remove("Doe",'J');
	// b.remove("Doe",'L');
	// b.inOrderPrint();
	//b.inOrderPrint();
	//cout << endl;
	// b.remove("Doe",'J');
	// b.inOrderPrint();
	// cout << endl;
	// b.remove("Doe",'J');
	// b.inOrderPrint();
	// cout << endl;
	// b.remove("Doe",'J');
	// b.inOrderPrint();
	// //test.insert(pt3.GetLast(),pt3.GetFirst(),pt3.GetAcct());
	// test.pushNode(pt3);
	// test.pushNode(pt4);
	// test.pushNode(pt5);
	
	//t.inOrderPrint();
	//b.inOrderPrint();
	cout << endl;
	// if (test.search("B",'Q')){
	// 	cout << "t" <<endl;
	// }
	// else{
	// 	cout<< "f" <<endl;
	// }	
	// test.remove("B",'Q');
	// test.remove("A",'P');
	// test.inOrderPrint();
	// cout << endl;
	// //test.remove("B",'P');
	// //test.inOrderPrint();
	// //cout << endl;
	// //test.remove("D",'S');

	// //test.inOrderPrint();

	// cout<<endl;
	
}