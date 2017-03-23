#include <iostream>
using namespace std;

void sort(long *arr, int n){
	int tmp;
	for (int i = 0;i < n;i++){
		for (int j = i; j > 0 ; j-- ){
			if (arr[j]<arr[j-1]){
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
			else{
				break;
			}
		}
	}

}
long mode (long *arr, int n) {
  // TO DO:: Fill in this function.
	int MaxCount,count;
	int MostFreqNum;
	int j = 1;
	if (n>0){
		sort(arr,n);
		MaxCount = 1;
		MostFreqNum = arr[0];
	}
	else{
		MaxCount = 0;
		return -1;
	}
	for (int i = 1;i<n;i++){
		if (arr[i] != arr[i-1]){
			count = 1;
		}
		else{
			count++;
			if (count > MaxCount ){
				MostFreqNum = arr[i];				
			}
		}

	}
	return MostFreqNum;
}
int main(){
	int n;
	long *arr;

	// Get the number of elements
	cout << "Enter the number of elements:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	arr = new long[n];

	for (int i=0; i<n; i++) {
		cout << "Enter a number:" << endl;
		cin >> arr[i];
	}
	//sort(arr,n);
	//cout << "new sorted array" << endl;
	// for (int i=0;i<n;i++) {
	// 	cout << arr[i] << endl;
	// }
	long modee = mode(arr,n);
	cout << modee << endl;
}
