#include <iostream>
using namespace std;
template <typename T>
T minuss(T const& a , T const& b){
	return a-b;
}
template <typename T1>
class ttst{

}
ttst::
int main(void){
	float i=1.4;
	float j = 2.5;
	cout << minuss(i,j) << endl;
}

/*#include <iostream>
using namespace std;
template <typename T1,typename T2>
class TEST {
public:
	T1 a;
	T2 b;
	T2 const& mmin(T1 const& a,T2 const& b);
	void mmax(T1 const& a,T2 const& b);
	T2 const& plus(T1 const& a,T2 const& b);
};
template <typename T1,typename T2>
void TEST<T1,T2>::mmax (T1 const& a,T2 const& b)
{
	T2 k = a>b? a:b;
	cout <<"mx " <<k<<endl;
	//cout << "max is " << a << endl;
	
}
template <typename T1,typename T2>
T2 const& TEST<T1,T2>::mmin (T1 const& a,T2 const& b)
{
	return a<b? a:b;
}
template <typename T1,typename T2>
T2 const& TEST<T1,T2>::plus (T1 const& a,T2 const& b){
	return a+b;
}
int main(){
	TEST<int,float> t;
	t.mmax(3,5.7);
	cout << t.mmin(1,4.5) << endl;
	cout << t.plus(3,3.0);
}*/
