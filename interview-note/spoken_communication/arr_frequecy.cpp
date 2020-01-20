#include <iostream>
#include <vector>
#include <stdio.h>
#include <array>
#include <map>

using namespace std;

void freq_measure(std::vector<int>& v, std::map<int,int>& m)
{
	if(v.empty())
		return;
	for(auto pos=v.begin(); pos != v.end(); ++pos)
	{
		m[*pos] = m[*pos]+1;
	}

}

int main()
{
	std::vector<int> v1={10,11,23,21,23,34,45,23};
	std::map<int,int> m1;
	freq_measure(v1,m1);
	for(auto e : m1)
	{
		std::cout << e.first << " frequency " << e.second << std::endl;
	}
}
