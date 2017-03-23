/*
 * Node.h
 *
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
	friend class ATMQueue;
public:
	Node();
	Node(int a);
	~Node();
	int getdata();
	void changedata(int k);

private:
	int data;
	Node *next;

};


#endif /* NODE_H_ */
