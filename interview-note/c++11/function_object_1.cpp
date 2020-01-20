#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>


using namespace std;
using namespace std::placeholders;

/* Function as algorithim argument,User defined auxilary function*/
void print(int elem)
{
	std::cout << elem << " ";
}
int square(int elem)
{
	return elem*elem;
}

//predicate:- is a special kind of auxilary function,return a bool value.
//Used to specify a sorting or searching criteria.
//unary predicate function

bool isPrime(int n)
{
	n=abs(n);
	if(n==0 || n==1)
	{
		return false;
	}
	for(int i=2; i <= n/2; i++)
	{
		if( n % i ==0)
			return false;
	}
	return true;
}

bool isPrime_1(int n)
{
	n=abs(n);
	if(n==0 || n==1)
	{
		return false;
	}
	int divisor;
	for(divisor=n/2; n % divisor !=0; --divisor);
	return  divisor==1;
}

//Function object
//When a user-defined class overloads the function call operator, operator(), it becomes a FunctionObject type.

//Binary predicate function
bool isGreater(int a, int b)
{
	return a > b;
}
//return whether a person is less than another person

struct  Person{
	string fname;
	string lname;
	Person(string fname, string lname):fname(fname),lname(lname){}
};
bool PersonSortCriteria(const Person& p1, const Person p2)
{
	return (p1.lname < p2.lname || (p1.lname ==p2.lname && p1.fname < p2.fname));
}



//add certain value to all elements of collection

void add10(int& elem)
{
	elem =elem + 10;
}

template<int theValue>
void add(int& elem)
{
	elem +=theValue;
}
struct  AddValue{
	int val;
	AddValue(int val):val(val){}
	void operator()(int& elem)
	{
		elem +=val;
	}
};
int xx=20;
int yy=30;

bool isInBetween(int elem)
{
	return elem > xx && elem < yy;
}	

struct InBetween
{
	int x;
	int y;
	InBetween(int x, int y):x(x),y(y){}
	bool operator()(int elem) const
	{
		return elem > x && elem < y;
	}
};
int main()
{
	//function pointer as algorithim argument
	std::vector<int> v1={1,2,3,4};
	std::for_each(v1.cbegin(),v1.cend(),print);
	std::cout << "\n";
	//transform each elemnt from coll1 into coll2 with squared transformed values
	std::vector<int> v2={1,2,3,4};
	std::vector<int> v3;
	std::transform(v2.begin(),v2.end(),back_inserter(v3),square);
	std::for_each(v2.cbegin(),v2.cend(),print);
	std::cout << "\n";
	std::for_each(v3.cbegin(),v3.cend(),print);
	std::cout << "\n";
	//copy from coll1 into coll2 if the element is prime number.
	std::vector<int> v4={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	std::vector<int> v5;
	std::copy_if(v4.begin(),v4.end(),back_inserter(v5),isPrime_1);
	std::for_each(v4.cbegin(),v4.cend(),print);
	std::cout << "\n";
	std::for_each(v5.cbegin(),v5.cend(),print);
	std::cout << "\n";
	//add a certain value to all elements of the container
	std::vector<int> v6={1,2,3,4};
	std::for_each(v6.cbegin(),v6.cend(),print);
	std::cout << "\n";
	std::for_each(v6.begin(),v6.end(),add10);
	std::for_each(v6.cbegin(),v6.cend(),print);
	std::cout << "\n";
	std::for_each(v6.begin(),v6.end(),add<10>);
	std::for_each(v6.cbegin(),v6.cend(),print);
	std::cout << "\n";
	std::for_each(v6.begin(),v6.end(),AddValue(10));
	std::for_each(v6.cbegin(),v6.cend(),print);
	std::cout << "\n";
	//add first elemnt of container to all elemnts of the container
	std::for_each(v6.begin(),v6.end(),AddValue(*v6.begin()));
	std::for_each(v6.cbegin(),v6.cend(),print);
	std::cout << "\n";
	//find the first elemnt with a value between x and y.
	int x=20;
	int y=30;
	std::vector<int> v7={12,23,45,67,98,35,10};
	/*traditional solution */
	vector<int>::iterator pos;
	for(pos=v7.begin(); pos!=v7.end(); ++pos)
	{
		if( *pos > x && *pos < y){
			break;
		}
	}
	cout << "The first element is :" << *pos << "\n";
	/* using binder */
	pos=find_if(v7.begin(), v7.end(), //range
			bind(logical_and<bool>(),
				bind(greater<int>(),_1,x),
				bind(less<int>(),_1,y)));
	cout << "**The first element is :" << *pos << "\n";

	pos = find_if(v7.begin(),v7.end(),isInBetween);
	cout << "*The first element is :" << *pos << "\n";
	pos=find_if(v7.begin(),v7.end(),InBetween(20,30));
	cout << "*The first element is :" << *pos << "\n";
	/* lambda - very eassy, it is the benifits of lambda*/
	pos = find_if(v7.begin(),v7.end(),[=](int elem){ return elem > x && elem < y;});
	cout << "The first element is :" << *pos << "\n";
	//from c++14
	pos = find_if(v7.begin(),v7.end(),[m=40,n=50](int elem){ return elem > m && elem < n;});
	cout << "The first element is :" << *pos << "\n";
	// Find that a range contain the number 25 and 35 or not, and also tell me which is first and wich is second one.
	
	

	
	return 0;
}

