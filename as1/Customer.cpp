#include "Customer.h"
Customer::Customer(){
	int start = 0;
	int end = 0;
}
int Customer::CustomerBegin(int *atime_list,int minute,int total_customer){
	int i;
	for(i=0;i<total_customer;i++){
		if(atime_list[i]>=minute){
			start=i;
			break;
		}
	}
	return start;

}
int Customer::CustomerEnd(int *atime_list,int minute,int total_customer){
	int j = start;
	while(atime_list[j]==minute && j<total_customer){
		j++;
	}
	if(atime_list[j-1]==minute){
		end = j-1;
	}
	return end;
}
// TO DO:: Fill in.


