#include <iostream>
#include <fstream>
using namespace std;

// Here I've left the code as I found it, to show you
// a contrasting (and in my opinion, nowhere near as clear)
// style.  Many C++ coders have this style.


// Find the mode of an array.
//
// Parameters:
//  arr is an integer array with n elements
// Return value:
//  return the mode
//
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
	if (n>0){
		// sort the array to find the mode easier.
		sort(arr,n);
		MaxCount = 1;
		MostFreqNum = arr[0];
	}
	else{
		// no mode for this condition
		MaxCount = 0;
		return -1;
	}
	for (int i = 1;i<n;i++){
		// The condition when the previous number != current number,
		// then reset count
		if (arr[i] != arr[i-1]){
			count = 1;
		}
		else{
			// The condition when the previous number = current number
			count++;
			if (count > MaxCount ){
				MostFreqNum = arr[i];				
			}
		}
	}
	return MostFreqNum;
}



// Input is the number of elements, followed by that many integers.
// Writes mode of elements to file specified as first command-line argument.
int main (int argc,  char* argv[]) {

	// ofstream for writing result.
	ofstream outputfile;

	// Parse command-line arguments.
	if (argc != 2) {
		// Note that the program name is the first argument, so argc==1 if there are no additional arguments.
		cerr << "Expected one argument." << endl;
		cerr << "  Usage: " << argv[0] << " output_filename" << endl;
		return 1;
	} else {
		// Open the filename specified for input.
		outputfile.open (argv[1]);
	}


	// Read a set of elements into an array.
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

	long m = mode(arr,n);

	cout << "The mode is " << m << endl;

	outputfile << m << endl;
	outputfile.close();

	// Free up memory.  Note use of delete [], since this is an array.
	delete [] arr;

	return 0;
}
