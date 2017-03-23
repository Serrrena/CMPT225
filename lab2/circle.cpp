#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle(){
	X = 0;
	Y = 0;
	radius = 10.0;
}
Circle::Circle(int x,int y,double r){
	X = x;
	Y = y;
	if (r>=0){
		radius = r;
	}
	else{
		radius = 10.0;
	}
}
void Circle::move(int m,int n){
	X = X+m;
	Y = Y+n;
}
void Circle::setRadius(double r){
	if (r>=0){
		radius = r;
	}
	else{
		radius = 10.0;
	}
}
int Circle::getX(){
	return X;
}
int Circle::getY(){
	return Y;
}
double Circle::getRadius(){
	return radius;
}
double Circle::getArea(){
	//const double pi = boost::math::constants::pi<float>();
	const double PI = 3.1415927;
	double area = PI*radius*radius;
	return area;
}
void Circle::displayCircle(){
	cout<<"radius "<< radius << " at point x = " <<X<< ", y = "<<Y<<endl;
}
bool Circle::intersect(Circle c){
	double distance = sqrt(pow((X-c.X),2)+pow((Y-c.Y),2));
	if(distance<=c.radius+radius and distance >=abs(c.radius-radius)){
		return true;
	}
	else{
		return false;
	}
}