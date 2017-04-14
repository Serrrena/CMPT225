
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <iostream>
using namespace std;
/*#include <string>
#include <iostream>
using namespace std;*/
//class Node;
class Customer {
//friend class Node;
public:
	Customer();
	Customer(string LastName,char FirstInitial,int AcctBalance);
	~Customer();
	bool operator<(const Customer & c) const;
	bool operator<=(const Customer & c) const;
	bool operator>(const Customer & c) const;
	bool operator>=(const Customer & c) const;
	bool operator==(const Customer & c) const;
	bool operator!=(const Customer & c) const;
	friend ostream& operator<<(ostream & os,  Customer & c);
	string GetLastName();
	char GetFirstInitial();
	int GetAcctBalance();
	void SetLastName(string last);
	void SetFirstInitial(char initial);
	void SetAcctBalance(int acctb);
private:
	string LastName_;
	char FirstInitial_;
	int AcctBalance_;
};

#endif /* CUSTOMER_H_ */
