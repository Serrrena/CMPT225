#include <iostream>
using namespace std;
class Queue{
public:
	Queue(int k){
		front = 0;
		back = 0;
		count = 0;
		totalelement = k;
		data = new int[k];
	 	for (int i=0;i<totalelement;i++){
	 		data[i] = 0;
	 	}
	}
	void insert(int a){
		if (count == totalelement){
			cout << "queue is full" << endl;
		}
		else{
			data[back] = a;
			back = (back+1)%totalelement;
			count++;
		}
	}
	void remove(){
		if (count == 0){
			cout << "queue is empty" << endl;

		}
		else{
			data[front] = 0;
			front = (front+1)%totalelement;
			count--;
		}
	}
	void printQ(){
		int i = 0;
		int k = front;
		while (i<count){

			cout << data[k] << " ";
			k = (k+1)%totalelement;
			i++;
		}
		cout << endl;
	}
private:
	int *data;
	int front;
	int back;
	int totalelement;
	int count;
};
int main(void){
	Queue q = Queue(10);
	for (int i=0;i<4;i++){
		q.insert(i*2);
	}
	
	for (int i=4;i<10;i++){
		q.insert(i*3);
	}
	
	for (int i=0;i<6;i++){
		q.remove();
	}
	q.printQ();
	for (int i=0;i<8;i++){
		q.insert(i*2);
	}
	q.printQ();

}