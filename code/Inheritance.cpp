#include <iostream>

using namespace std;

class Shape{
public:
	Shape(){w=0;l=0;};
	Shape(int w, int l){this->l = l;this->w = w;};
	void area(){
		cout << "area is " << w*l << endl;
	}
protected:
	int l;
	int w;
};
class Rectangle : public Shape{
public:
	Rectangle(int w, int l);
	void area(){
		cout << "area is " << w*w*l*l << endl;
	}

};

Rectangle::Rectangle(int w,int l):Shape(w,l){}

int main(void){
	Shape b(2,5);
	Shape *a = new Rectangle(2,5);
	//a->Shape::area();
	a->area();
	//Shape b = Rectangle()
}