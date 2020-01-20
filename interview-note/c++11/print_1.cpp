#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

template < typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr="")
{
        std::cout << optstr;
        for(const auto& elem:coll){
                std::cout << elem << ' ';
        }
        std::cout << std::endl;
}
//-------------------------------------------------------------


template <typename T>
void print_0(const T& coll)
{
	typename T::const_iterator pos;
	pos=coll.begin();
	while(pos != coll.end())
	{
		std::cout << *pos++ << " ";
	}
	std::cout << "\n";
}
//----------------------------------------

template<typename T>
void print_1(const T& coll)
{
        for(const auto & elem: coll)
	{
                std::cout <<' ' <<elem;
        }
        std::cout << endl;
}
//--------------------------------------------------
template<typename T>
void print_2(const T& coll)
{
	std::copy(coll.cbegin(), coll.cend(),ostream_iterator<int>(cout," "));
	std::cout << "\n";
}
//-------------------------------------------------------------------

//Function pointer
template<typename T>
void printElem(T elem)
{
	cout << elem << " ";
}
template <typename T>
void print_3(const T& coll)
{
	typedef typename T::value_type VT;
	for_each(coll.cbegin(),coll.cend(),printElem<VT>);
	std::cout << endl;
}
//Function Object
template<typename T>
struct PrintElem{
	void operator()(T elem) { std::cout << elem << " ";}
};


template<typename T>
void print_4(const T& coll)
{
	typedef typename T::value_type VT;
        for_each(coll.cbegin(), coll.cend(),PrintElem<VT>());
        std::cout << endl;
}
template<typename T>
void print_5(const T& coll)
{
	typedef typename T::value_type VT;
	PrintElem<VT> printer;
        for_each(coll.cbegin(), coll.cend(),printer);
        std::cout << endl;
}
//using lambda
template<typename T>
void print_6(const T& coll)
{
	for_each(coll.cbegin(), coll.cend(),[](int elem){ cout << elem << " ";});
        std::cout << endl;
}

int main()
{
	//std::list<int> l1;
	//std::copy(std::istream_iterator<int>(cin),std::istream_iterator<int>(),back_inserter(l1));
	std::list<int> l2={1,2,3,4};
	print_2(l2);
}
