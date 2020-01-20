#include <iostream>
#include<functional>
#include <vector>
#include <algorithm>

//general programming using lambda.

using namespace std;

//Function returning lambda.
std::function<int(int,int)> f1()
{
	return [](int x, int y){
		return x+y;
	};
}
class PrintElements
{
	public:
		void operator()(int elem)
		{
			cout << elem << '\n';
		}
};
int main()
{
	auto lf=f1();
	cout << lf(6,7) << '\n';
	std::vector<int> v1{1,2,3};
	for_each(v1.begin(), v1.end(),[](int x){ cout << x << endl;});
	for_each(v1.begin(), v1.end(),PrintElements());
}

