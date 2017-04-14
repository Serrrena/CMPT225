#include <iostream>
#include <vector>
using namespace std;
int main(void){
	vector<int> test;
	vector<int>::iterator testIter;
	test.push_back(4);
	test.push_back(8);
	test.push_back(11);
	test.push_back(43);
	for (testIter = test.begin();testIter!=test.end();testIter++){
		cout<< *testIter << endl;
	}

}
