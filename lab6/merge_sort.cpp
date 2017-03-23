#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);




// Perform mergeSort to sort an array of integers.
// Inputs:
//   arr is the input array of arrSize integers.
//   low and high are the indices to sort to/from, e.g. 0 arrSize-1 to sort entire array
// Postcondition:
//   arr[low] ... arr[high] will contain the original values, sorted in increasing order.
void mergeSort(int arr[], int low, int high) {
	if (high-low <= 0 ){
		return;
	}
	int mid  = (low+high)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}


// Perform a merge of two sorted sub-arrays.
// Inputs:
//   arr is the input array on which to perform a merge.
//   low-mid and (mid+1)-high are the two sub-arrays to merge.
// Precondition:
//   arr[low]...arr[mid] is sorted in increasing order.
//   arr[mid+1]...arr[high] is sorted in increasing order.
//   These should be disjoint, contiguous sub-arrays too.
// Postcondition:
//   arr[low]...arr[high] is sorted in increasing order.
void merge(int arr[], int low, int mid, int high) {

	int i = low;
	int pos = low;
	int j = mid+1;
	int newarr[high+1];
	while(i<=mid && j<=high){
		if (arr[i]<arr[j]){
			newarr[pos] = arr[i];
			i++;
		}
		else{
			newarr[pos] = arr[j];
			j++;
		}
		pos++;
	}
	if (i == mid+1){
		while (pos<=high){
			newarr[pos] = arr[j];
			j++;
			pos++;
		}
	}
	else{
		while (pos<=high){
			newarr[pos] = arr[i];
			i++;
			pos++;
		}
	}
	for (int k = low;k <= high;k++){
		arr[k] = newarr[k];
	}
}


// A driver program to test mergeSort.
// Reads in a number of integers (number, then sequence of values).
// Sorts using mergeSort.
// Prints the values in sorted order.
int main (void) {
	int n;

	// Get the number of values.
	//	cout << "Enter the number of values to be sorted:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	int *values;
	values = new int[n];

	for (int i=0; i<n; i++) {
		// cout << "Enter a number:" << endl;
		cin >> values[i];
	}

	// Call mergeSort to sort entire array.
	mergeSort(values,0,n-1);

	// Print values, should be sorted.
	for (int i=0; i<n; i++) {
		cout << values[i] << " ";
	}
	cout << endl;


	// Free the dynamic memory we allocated.
	// Note use of delete [], since this is an array.
	delete [] values;

	return 0;
}
