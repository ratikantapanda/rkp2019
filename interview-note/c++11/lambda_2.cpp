#include <iostream>

using namespace std;

int main()
{
	//Lambda introducer i.e [..] and access to outer scope- non-static variables.
	//No issue to access static and global varibles.
	//[] - can't access outer scope non-static variables.Only static and global variables can.
	//[=] - outer scopes are passed by value,only readonly access.
	//[&]- outer scope are pased by reference, with read and write access.
	//[x,&y] - x is passed by value and y passed by reference.
	//[=,&y] - except y all outer scope variables are passed by reference.
	//[x,&]
	int x=42,y=43;
	auto lf1=[x,&y]{ 
		std::cout << x << std::endl;
		std::cout<< y << std::endl;
		y++;
	};
	x=52,y=53;
	lf1();
	lf1();
	cout << "Final value of y " << y << endl;
	int id=0;
	//mutable lambda-object are passed by value, but have write access inside the function object.
	//with mutable lambda become stateful.
	auto lf2=[id]()mutable{
		std::cout << "id: " << id << std::endl;
		++id;
	};
	id=42;
	lf2();
	lf2();
	lf2();
	std::cout << id << std::endl;
	//similar to nonconst operator()
	//const opearator() is similar to lamda without mutable.
	class X{
		int id;
		public:
		X(int id):id(id){}
		void operator()(){
			std::cout << "id: " << id << '\n';
			++id;
		}
	};
	X xx(10);
	xx();
	xx();
}


