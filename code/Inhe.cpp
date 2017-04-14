#include <iostream>
using namespace std;
class Animal
{
public:
	static int count;
	Animal();
	Animal(int a);
	virtual~Animal();
	virtual void sound();
	virtual int GetAge();
private:
	int age_;

};
class Sheep : public Animal
{
public:
	Sheep();
	Sheep(int a);
	~Sheep();
	void sound();
	int GetAge();
private:
	int age_;
};

Animal::Animal(){
	age_ = 0;
	//count++;
	cout<<"Animal create"<<endl;
}
Animal::Animal(int a){
	age_ = a;
	count++;
	cout<<"Animal create"<<endl;

}
Animal::~Animal(){
	age_ = 0;
	count = 0;
	cout << "Animal delete" << endl;
}
void Animal::sound(){
	cout << "ouch!" << endl;
}
int Animal::GetAge(){
	return age_;
}

Sheep::Sheep(){
	age_ = 0;
	//count++;
	cout<<"Sheep create"<<endl;

}
Sheep::Sheep(int a){
	age_ = a;
	count++;
	cout<<"Sheep create"<<endl;

}
Sheep::~Sheep(){
	age_ = 0;
	count = 0;
	cout << "Sheep delete" << endl;
}
void Sheep::sound(){
	cout << "beeee" << endl;
}
int Sheep::GetAge(){
	return age_; 
}

int Animal::count = 0;

int main(void){
	//Animal a(5);
	Animal* b = new Sheep(10);
	Sheep c(11);
	//a.sound();
	//b->sound();
	//cout<< a.GetAge()<<endl;
	//cout<< b->GetAge()<<endl;
	//cout<< Animal::count << endl;
	//delete b;
	return 0;
}