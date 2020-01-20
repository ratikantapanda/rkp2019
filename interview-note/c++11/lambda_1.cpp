#include <iostream>
using namespace std;

//Anonymous function object(i.e functor).
//Function object -> function with state.
//
//In c++ lambda are very useful for hash function or sorting criteria in unordered or associative container.


int main()
{
	//Minimal lambda
	auto lf1=[]{std::cout << "Hello World1" << std::endl;};
	lf1();
	//direct call of lambda
	[]{ std::cout << "Hello Wolrld-2" << std::endl;}();
       // Lambda can't be templates.
       auto lf4=[]{ return 42;} ;//Return type deduction from return value type.
       auto lf5=[]()->double{ return 42;}; //Return value 42.0, type double.
       auto a=1.0;
       std::cout << std::fixed << lf4() << " " <<lf5() << '\n';
	//lambda parameters i.e (...)
	auto lf2=[](const string& s){
		cout << s << '\n';
	};
	lf2("HELLO WORLD");
	return 0;

}

