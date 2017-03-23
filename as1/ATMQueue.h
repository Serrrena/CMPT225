/*
 * ATMQueue.h
 *
 */
#include "Node.h"
#ifndef ATMQUEUE_H_
#define ATMQUEUE_H_



class ATMQueue {
	friend class ATM;
  // TO DO:: Fill in.
public:
	ATMQueue();
	ATMQueue(int a);
	~ATMQueue();
	int size();
	bool ifempty();
	void enqueue(int b);
	void dequeue();
	int headdata();
	int taildata();

private:
	Node *front;
	Node *back;
	int number;
};

#endif /* ATMQUEUE_H_ */
