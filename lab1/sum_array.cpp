#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
using namespace std;

int sum_array(int *arr,int arrsize){
	int i,total;
	for (i = 0;i<arrsize;i++){
		total = total + arr[i];
	}
	return total;
}

int main(void){
	int *arr;
	arr = new int[3];
	cin >> arr[0];
	cin >> arr[1];
	cin >> arr[2];
	cout << sum_array(arr,3)<< endl;
}