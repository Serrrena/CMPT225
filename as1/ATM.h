#include "ATMQueue.h"
#ifndef ATM_H_
#define ATM_H_



class ATM {
	//friend class ATMQueue;
public:
	ATM();
	~ATM();
	bool IsEmpty();
	bool checkTimer();
	int GetTimer();
	int AtmQueueSize();
	int TotalCustomer();
	void ArrivalCustomer(int k);
	void ProcessNewCustomer();
	void ProcessCurrentCustomer();
	int GetWaitTime();
private:
	ATMQueue *atmque_;
	int checkempty_;
	int transaction_;
	int timer_;
	int wait_time_;

  // TO DO:: Fill in.
};

#endif /* ATM_H_ */
