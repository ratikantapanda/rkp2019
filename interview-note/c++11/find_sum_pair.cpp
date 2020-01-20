#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPairSumN(vector<int> v,int sum)
{
	vector<int>::iterator first=v.begin();
	vector<int>::iterator last=v.end();
	if(first == last) return false;
	while( std::next(first,1) != last)
	{
		if((*first + *std::next(first,1))==sum)
		{
			return true;
		}
		++first;
	}
	return false;
}

void findPair( vector<int> v,int sum)
{
	unordered_map<int,int> m1;
	std::size_t size=v.size();
	for(int i=0; i < size ;i++)
	{
		if(m1.find(sum -v[i]) !=m1.end())
		{
			cout << "pair indexes: " << m1[sum - v[i]] << ' ' << i<< '\n';
		        return;
		}
	        m1[v[i]]=i;
	}
	cout << "Pair not found" << '\n';
}

int main()
{
	std::vector<int> v1={20,10,10,11,10};
	bool result =isPairSumN(v1,20);
	std::cout << result << '\n';

	std::vector<int> v2= { 30,56,50,34,67};
	findPair(v2,90);
	return 0;
}

