/*
 * Customer.h
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
	//sort(int *ttime_list,int customer_begin, int customer_end);
public:
	Customer();
	int CustomerBegin(int *atime_list,int minute,int total_customer);
	int CustomerEnd(int *atime_list,int minute,int total_customer);
private:
	int start;
	int end;

};

#endif /* CUSTOMER_H_ */
