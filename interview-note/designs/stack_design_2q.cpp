#include <iostream>
#include <queue>

using namespace std;

struct mystack
{
	queue<int> q1;
	queue<int> q2;
	void push( int x)
	{
		q1.push(x);
	}
	void pop()
	{
		while(!q1.empty())
		{
			int e=q1.front();
			q1.pop();
			if(!q1.empty())
			{
				q2.push(e);
			}
		}
		while(!q2.empty())
		{
			int e=q2.front();
			q2.pop();
			q1.push(e);
		}
	}
	int top()
	{
		int top=0;
		while(!q1.empty())
		{
			int e=q1.front();
			q1.pop();
			q2.push(e);
			top=e;
		}
		while(!q2.empty())
		{
			int f=q2.front();
			q2.pop();
			q1.push(f);
		}
		return top;
	}

};
int main()
{
	mystack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	return 0;
}

