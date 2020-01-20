#include <iostream>
#include <stack>

using namespace std;

struct mystack
{
	stack<int> s1;
	stack<int> s2;
	int top()
	{
		if(s1.empty())
		{
			return 0;
		}
		return s1.top();
	}
	int min()
	{
		if(s2.empty())
		{
			return 0;
		}
		return s2.top();
	}
	void push(int x)
	{
		s1.push(x);
		if(x < s2.top())
		{
			s2.push(x);
		}
	}
	void pop()
	{
		if(!s1.empty())
		{
			if(s1.top()==s2.top())
			{
				s1.pop();
				s2.pop();
			}
		}
	}


/*
struct MyStack
{
    stack<int> s;
    int minEle;
 
    int  getMin()
    {
        if (s.empty())
	  return 0;
        else
		return minEle;
    }
 
    int top()
    {
        if (s.empty())
        {
            return 0;
        }
 
        int t = s.top(); // Top element.
        if(t < minEle)
		return minEle;
	else
		return t;
    }
 
    // Remove the top element from MyStack
    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
 
        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
 
        // Minimum will change as the minimum element
        // of the stack is being removed.
        if (t < minEle)
        {
            cout << minEle << "\n";
            minEle = 2*minEle - t;
        }
 
        else
            cout << t << "\n";
    }
 
    // Removes top element from MyStack
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
            return;
        }
 
        if (x < minEle)
        {
            s.push(2*x - minEle);
            minEle = x;
        }
        else
           s.push(x);
        cout <<  "Number Inserted: " << x << "\n";
    }
};*/
int main(){
	return 0;
}
