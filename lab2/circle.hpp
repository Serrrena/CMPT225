class Circle
{
public:
	Circle();
	Circle(int x,int y,double r);
	void move(int m,int n);
	void setRadius(double r);
	int getX();
	int getY();
	double getRadius();
	double getArea();
	void displayCircle();
	bool intersect(Circle c);
private:
	double radius;
	int X;
	int Y;
};