#include <bits/stdc++.h>

using namespace std;

int find_kth_highest(const std::vector<int>& v1, int k)
{
	if(v1.empty())
		return 0;
	std::priority_queue< int,vector<int> , std::less<int>  > pq1;
	for(auto pos=v1.begin(); pos != v1.end(); ++pos){
		pq1.push(*pos);
	}
	for ( int i=1; i < k ; i++)
	{
		pq1.pop();
	}
	return pq1.top();
}


int main()
{
	std::vector<int> v1={10,20,30,40,50,60,70,80,90};
	int k=3;
	int result1=find_kth_highest(v1,k);
	std::cout << result1 << std::endl;
}

