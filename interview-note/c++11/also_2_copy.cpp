#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include<iterator>

using namespace std;

int main()
{
	std::vector<int> v1={1,2,3,4};
	std::list<int> l1;
	//copy elements of v1 into l1.
	std::copy(v1.begin(),v1.end(),
			back_inserter(l1));
	for(const auto & e:l1)
	{
		std::cout << e << " ";
	}
	std::cout << '\n';
	//copy elements in reverse order.
	std::list<int> l2;
	for(const auto & e:l2)
	{
		std::cout << e << " ";
	}
	std::copy(v1.crbegin(),v1.crend(),
			back_inserter(l2));
	//copy elements into cout using ostream_iterator.
	std::copy(l1.begin(),l1.end(),
			std::ostream_iterator<int>(cout," "));
	std::cout << '\n';
	//read from cin into a container
	/*std::vector<int> v2;
	std::copy(istream_iterator<int>(cin),istream_iterator<int>(),
			back_inserter(v2));
	for(const auto & e:v2)
	{
		std::cout << e << " ";
	}
	*/
	//copy data between standard input into standard output.
	
	copy(istream_iterator<string>(cin),
			istream_iterator<string>(),
			ostream_iterator<string>(cout,"\n"));
	return 0;
}
