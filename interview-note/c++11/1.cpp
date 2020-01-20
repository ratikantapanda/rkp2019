#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::vector<int> v1={1,2,3,4};
	int* ptr=&v1[2];
	std::cout << *ptr << std::endl;
	v1.insert(v1.begin(),0);
	std::cout << *ptr << std::endl;
	//v1.insert(v1.begin(),100);
	std::cout << v1.front() << std::endl;
}

