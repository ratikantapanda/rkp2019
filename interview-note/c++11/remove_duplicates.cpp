#include <iostream>
using namespace std;

#define SIZE(a) \
	sizeof(a)/sizeof(a[0])

#define PRINT_ARRAY(a) \
	for(int e :a) { cout << e << " ";} \
	cout << '\n';



void print_arry(int a[],int n)
{
	for( int i=0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
        cout << '\n';
}

int removedup_sorted_array(int a[], int n)
{
	if( n==0 || n==1)
		return n;
	int i=1; // first hole 
	// walk through to find the next uniq number
	// if got swap with whole
	for(int j=1; j < n ; j++)
	{
		if(a[j-1] != a[j])
		{
			a[i]=a[j];
			i++;
		}
	}
	a[i]='\0';
	return i;
}

void move_zeros_end(int a[], int n)
{
	int pivot_value=0;
	//First avaliable position for non-zero elemnts.
	int i=0;
	//find non-zero elements and swap with avliable position
	for( int j=0; j < n; j++)
	{
		if(a[j]!=pivot_value)
		{
			swap(a[i],a[j]);
			i++;
		}
	}
}


int main()
{
	int a[]={1,1,2,2,2,3};
	PRINT_ARRAY(a);
	int n=removedup_sorted_array(a,SIZE(a));
	std::cout << n << '\n';
	PRINT_ARRAY(a);
	int b[]={0,1,0,0,2,3};
	PRINT_ARRAY(b);
        move_zeros_end(b,SIZE(b));
	PRINT_ARRAY(b);
	return 0;
}
