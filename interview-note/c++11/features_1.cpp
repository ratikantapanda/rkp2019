#include <iostream>
#include <vector>
#include <typeinfo>
 using namespace std;

class x{
};

x& f1(x& a)
{
	return a;
}


int main()
{
	//nullptr and std::nullptr_t
	////auto and automatic type deduction.
	vector<string> v1;
	auto pos=v1.begin(); //type vector<string>::iterator
	auto l=[](int x)->bool{ //type of lambda taking an int returning bool.
		return x==1;
	};
	x a;
	auto& r1=f1(a);
}


