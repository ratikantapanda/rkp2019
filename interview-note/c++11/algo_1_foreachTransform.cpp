#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

using namespace std::placeholders;

//Function object that add the value with wich it is initialized.
template<typename T>
struct  AddValue
{
	T val;
	AddValue(const T& val):val(val){}
	void operator()(T& elem)
	{
		elem += val;
	}
};
struct MeanValue
{
	int num;
	long  sum;
	MeanValue():num(0),sum(0){}
	//function call
	void  operator()(int elem)
	{
		num=num+1;
		sum = sum + elem;
	}
	//return mean value(implicit type conversion)
	operator double()
	{
		return static_cast<double>(sum)/static_cast<double>(num);
	}
};


int main()
{
	std::vector<int> v1={1,2,3,4};
	//print elements
	std::for_each(v1.cbegin(),v1.cend(),[](int elem){ cout << elem << ' ' ;});
	cout << '\n';
	//add 10 to each element
	std::for_each(v1.begin(),v1.end(),[](int& elem){ elem +=10; });
	std::for_each(v1.begin(),v1.end(),AddValue<int>(10));
	for(const auto& elem:v1)
	{
		std::cout << elem << ' ';
	}
	cout << '\n';
	// add value of first element to each element.
	//std::for_each(v1.begin(),v1.end(),[&](int& elem){ elem +=*v1.begin();});
	std::for_each(v1.begin(),v1.end(),[=](int& elem){ elem +=*v1.begin();});
	std::for_each(v1.begin(),v1.end(),AddValue<int>(*v1.begin()));
	for(const auto& elem:v1)
	{
		std::cout << elem << ' ';
	}
	cout << '\n';
	std::vector<int> v2= { 1,2,3,4};
	//add 10 to each element.
	std::transform(v2.begin(),v2.end(),v2.begin(),[](int elem){ return elem +10;});
	 for(const auto& elem:v2)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';
	std::transform(v2.begin(),v2.end(),v2.begin(),[=](int & elem){ return elem + *v2.begin();});
	 for(const auto& elem:v2)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';
	//return value of for_each
	//Mean value of a container
	// lambda is not necessarily better, because a finction object encapsulate both sum as internal state.
	std::vector<int> v3={1,2,3,4};
	double result1=std::for_each(v3.begin(),v3.end(),MeanValue());
	std::cout << result1 << std::endl;

	//negate all element
	std::transform(v3.begin(), v3.end(),v3.begin(),std::negate<int>());
	for(const auto& elem:v3)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';

	std::vector<int> v4={1,2,3,4};
	std::vector<int> v5;
	std::transform(v4.begin(),v4.end(),
			std::back_inserter(v5), //do not use v2.begin(),segmentation fault
			[](int elem){ return elem*10;});
	std::transform(v4.begin(),v4.end(),
			back_inserter(v5),
			std::bind(std::multiplies<int>(),_1,100));
	for(const auto& elem:v5)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';
	//print v5  negatively and reverse order
	std::transform(v5.rbegin(),v5.rend(),
			ostream_iterator<int>(cout," "),
			[](int elem) { return -elem; });

	cout << '\n';
	//square each element
	std::vector<int> v6={2,4,6};
	std::for_each(v6.begin(),v6.end(),[](int& elem){ elem = elem*elem;});
	for(const auto& elem:v6)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';
	std::transform(v6.begin(),v6.end(),
			v6.begin(),
			[](int elem){ return elem* elem;});
	for(const auto& elem:v6)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';
	//combining element of two sources.
	std::transform(v6.cbegin(),v6.cend(), //first source range
			v6.cbegin(), //second source range
			v6.begin(), //destination range
			multiplies<int>()); //operation
	for(const auto& elem:v6)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';
	//add each element traversed forward with each elemnt travversed backward.
	//and insert result into a container
	std::vector<int> v7={1,2,3,30,20,10};
	std::vector<int> v8;
	std::transform(v7.cbegin(),v7.cend(),
			v7.crbegin(),
			back_inserter(v8),
			std::plus<int>());
	for(const auto& elem:v8)
        {
                std::cout << elem << ' ';
        }
	cout << '\n';
	//print difference of corresponding elements inbetween two container.
	std::vector<int> v9={1,2,3,4};
	std::vector<int> v10={10,20,30,40,50};
	std::transform(v9.begin(),v9.end(),
			v10.cbegin(),
			ostream_iterator<int>(cout, " "),
			std::minus<int>());



	return 0;
}
