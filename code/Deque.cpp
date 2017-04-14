#include <iostream>
using namespace std;
class Deque{
public:
	Deque(int k){
		front = 0;
		back = 0;
		count = 0;
		totalelement = k;
		data = new int[k];
	 	for (int i=0;i<totalelement;i++){
	 		data[i] = 0;
	 	}
	}
	void pushback(int a){
		if (count == totalelement){
			cout << "queue is full" << endl;
		}
		else{
			data[back] = a;
			back = (back+1)%totalelement;
			count++;
		}
	}
	void pushfront(int a){
		if (count == totalelement){
			cout << "queue is full" << endl;
		}
		else{
			front = (front-1)%totalelement;
			data[front] = a;
			count++;
		}
	}
	void popfront(){
		if (count == 0){
			cout << "queue is empty" << endl;

		}
		else{
			data[front] = 0;
			front = (front+1)%totalelement;
			count--;
		}
	}
	void popback(){
		if (count == 0){
			cout << "queue is empty" << endl;

		}
		else{
			data[(back-1)%totalelement] = 0;
			back = (back-1)%totalelement;
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
	Deque q = Deque(15);
	for (int i=0;i<4;i++){
		q.pushfront(i*2);
	}
	
	for (int i=4;i<13;i++){
		q.pushback(i*3);
	}
	q.printQ();
	for (int i=0;i<5;i++){
		q.popback();
	}
	for (int i=0;i<3;i++){
		q.popfront();
	}
	
	q.printQ();

}