#include "Customer.h"

Customer::Customer():LastName_(""),FirstInitial_(0),AcctBalance_(0){}

Customer::Customer(string x, char y, int z) {
	LastName_ = x;
	FirstInitial_ = y;
	AcctBalance_ = z;
}
Customer::~Customer(){
	LastName_ = "";
	FirstInitial_ = 0;
	AcctBalance_ = 0;
}
bool Customer::operator<(const Customer & c) const{
	if(this->LastName_ < c.LastName_){
		return true;
	}
	else if(this->LastName_ == c.LastName_){
		if(this->FirstInitial_ < c.FirstInitial_){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}

}
bool Customer::operator<=(const Customer & c) const{
	if(!((*this) > c)){
		return true;
	}
	return false;
}
bool Customer::operator>(const Customer & c) const{
	if(this->LastName_ > c.LastName_){
		return true;
	}
	else if(this->LastName_ == c.LastName_){
		if(this->FirstInitial_ > c.FirstInitial_){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}

}
bool Customer::operator>=(const Customer & c) const{
	if(!((*this) < c)){
		return true;
	}
	return false;
}
bool Customer::operator==(const Customer & c) const{
	if (this->LastName_==c.LastName_ && this->FirstInitial_ == c.FirstInitial_){
		return true;
	}
	return false;
}
bool Customer::operator!=(const Customer & c) const{
	if (!((*this) == c)){
		return true;
	}
	return false;
}

ostream& operator<<(ostream & os,  Customer & c) {
	os << c.LastName_ << ", " << c.FirstInitial_ << ". (" << c.AcctBalance_ << ")" ; 
}
string Customer::GetLastName(){
	return this->LastName_;
}
char Customer::GetFirstInitial(){
	return this->FirstInitial_;
}
int Customer::GetAcctBalance(){
	return this->AcctBalance_;
}
void Customer::SetLastName(string last){
	this->LastName_ = last;
}
void Customer::SetFirstInitial(char initial){
	this->FirstInitial_ = initial;
}
void Customer::SetAcctBalance(int acctb){
	this->AcctBalance_ = acctb;
}