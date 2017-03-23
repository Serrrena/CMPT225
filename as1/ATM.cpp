#include "ATM.h"
#include "ATMQueue.h"
	
ATM::ATM(){
	atmque_ = new ATMQueue();
	checkempty_ = 0;
	transaction_ = 0;
	timer_ = 0;
	wait_time_ = 0;
}
ATM::~ATM(){
	delete atmque_;
	checkempty_ = 0;
	transaction_ = 0;
	timer_ = 0;
	wait_time_ = 0;
}
bool ATM::IsEmpty(){
	if (checkempty_ == 0){
		return true;
	}
	else{
		return false;
	}
}
bool ATM::checkTimer(){
	if (timer_ == 0){
		return true;
	}
	else{
		return false;
	}
}
int ATM::GetTimer(){
	return timer_;
}
int ATM::AtmQueueSize(){
	return atmque_->size();
}
int ATM::TotalCustomer(){
	if (IsEmpty()){

		return AtmQueueSize();
	}
	else{
		return 1+AtmQueueSize();		
	}
	
}
void ATM::ArrivalCustomer(int k){
	atmque_->enqueue(k);
}
void ATM::ProcessNewCustomer(){
	if (IsEmpty()){
		transaction_ = atmque_->headdata();
		atmque_->dequeue();
		checkempty_ = 1;
		timer_ = transaction_;
	}
}

void ATM::ProcessCurrentCustomer(){	
	if (timer_ > 0 ){
		timer_--;
	}
	if (timer_ == 0){
		checkempty_ = 0;
	}

	wait_time_ = wait_time_ + atmque_->size();

}

int ATM::GetWaitTime(){
	return wait_time_;
}
