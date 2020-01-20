#include <iostream>
//factorial
//prime number
//fabonaci series

using namespace std;

bool isEven(int n)
{
	int result=n & 1;
	if(result==1)
	{
		cout << "odd" << '\n';
	}
	else
	{
		cout << "even" << '\n';
	}
	return result ==0;
}

//iterative

long long fact_i(int n)
{
	if(n  < 0)
	{
		return -1;
	}

	int fact=1;
	for(int i=1; i <= n; ++i){
		fact=fact*i;
	}
	return fact;
}
//recursive
long long fact_r(int n)
{
	if( n <= 1)
	{
		return 1;
	}
	return n*fact_r(n-1);
}
//----------------------------------------------------------------------------

bool isprime(int n)
{
	if(n==0 || n==1)
		return false;
	int divisor;
	for(divisor=n/2; n % divisor != 0; --divisor)
	{
		;
	}
	return 1==divisor;
}

//-------------------------------------------------------------------------------
//total n numbers in the series.
void fibonacci_series(int n)
{
    cout << "Fibonacci Series: " << endl;
    int t1=0;
    int t2=1;
    int tn;
    for (int i = 1; i <= n; ++i)
    {
	cout << t1 <<" ";
        tn= t1 + t2;
        t1 = t2;
        t2 = tn;
    }
}
//until certain number
void _fibonacci_series(int n)
{
    cout << "Fibonacci Series: " << endl;
    int t1=0;
    int t2=1;
    cout << t1 << " " << t2 << " ";
    int tn=t1+t2;
    while(tn <=n)
    {
        cout << tn <<" ";
        t1 = t2;
        t2 = tn;
        tn= t1 + t2;
    }
}
//find the nth number in Fibonacci series using recursion
int fibo(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return(fibo(num - 1) + fibo(num - 2));
}
//----------------------------------------------
int gcd(int x, int y) 
{
    int r = 0, a, b;
    a = (x > y) ? x : y; // a is greater number
    b = (x < y) ? x : y; // b is smaller number

    r = b;
    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

int lcm(int x, int y) 
{
    int a;
    a = (x > y) ? x : y; // a is greater number
    while (1) {
        if (a % x == 0 && a % y == 0)
            return a;
        ++a;
    }
}



int main()
{
	std::cout << isEven(3) << '\n';
	std::cout << isEven(100) << '\n';
	return 0;
}
