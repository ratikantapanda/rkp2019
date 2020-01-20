// array_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;


class array
{
	private :
		int size;
		int* element;
public :
		explicit array(int size_value=10);//default constructor
		array(const array& theArray);//copy constructor
		~array();//destructor

		void insert ( int pos, int num ) ;
		void del ( int pos ) ;
		void reverse( ) ;
		void display( ) ;
		void search ( int num ) ;
		void sort();
		void create(int sz);
		void merge(array&,array&);
} ;
//default constructor
array::array(int size_value):size(size_value),element(new int[size]){for(int i=0;i < size;i++) element[i]=0;}
//copy constructor
array::array(const array& theArray){size=theArray.size;
element=new int[size];
for(int i=0;i < size;i++)
element[i]=theArray.element[i];}

//destructor
array::~array(){delete [] element;}

 //inserts an element num at given position pos
void array :: insert ( int pos, int num )
{int i;
	// shift elements to right
	for (  i = size - 1 ; i >= pos ; i-- )
		element[i] = element[i - 1] ;
	element[i] = num ;
}

// deletes an element from the given position pos
void array :: del ( int pos )
{int i;
	// skip to the desired position
	for ( i = pos ; i < size ; i++ )
		element[i - 1] = element[i] ;
	element[i - 1] = 0 ;
}

// reverses the entire array
void array :: reverse( )
{
	for ( int i = 0 ; i < size / 2 ; i++ )
	{
		int temp = element[i] ;
		element[i] = element[size - 1 - i] ;
		element[size - 1 - i] = temp ;
	}
}

// searches array for a given element num
void array :: search ( int num )
{int i;
	// Traverse the array
	for ( i = 0 ; i < size ; i++ )
	{
		if ( element[i] == num )
		{
			cout << "\n\nThe element " << num << " is present at "<< ( i + 1 ) << "th position" ;
			return ;
		}
	}

	if ( i == size )
		cout << "\n\nThe element " << num << " is not present in the array" ;
}
// displays the contents of a array
void array :: display( )
{
	cout<< endl ;
	// traverse the entire array
	for ( int i = 0 ; i < size ; i++ )
		cout << "  " << element[i] ;
}
//
void array :: sort( )
{
	int temp ;
	for ( int i = 0 ; i < size ; i++ )
	{
		for ( int j = i + 1 ; j < size ; j++ )
		{
			if ( element[i] > element[j] )
			{
				temp = element[i] ;
				element[i] = element[j] ;
				element[j] = temp ;
			}
		}
	}
}

void array :: create ( int sz )
{
	size = sz ;
	element = new int[size] ;

	int n ;

	for ( int i = 0 ; i < size ; i++ )
	{
		cout << "\nEnter the element no. " << ( i + 1 ) << " " ;
		cin >> n ;
		element[i] = n ;
	}
}

void array :: merge ( array &a, array &b )
{
	int i, k, j ;
	size = a.size + b.size ;

	element = new int[size] ;

	for ( k = 0, j = 0, i = 0 ; i <= size ; i++ )
	{
		if ( a.element[k] < b.element[j] )
		{
			element[i] = a.element[k] ;
			k++ ;
			if ( k >= a.size )
			{
				for ( i++ ; j < b.size ; j++, i++ )
					element[i] = b.element[j] ;
			}
		}
		else
		{
			element[i] = b.element[j] ;
			j++ ;
			if ( j >= b.size )
			{
				for ( i++ ; k < a.size ; k++, i++ )
					element[i] = a.element[k] ;
			}
		}
	}
}
int main()
{
	array a ;

	a.insert ( 1,11 ) ;
	a.insert ( 2,12 ) ;
	a.insert ( 3,13 ) ;
	a.insert ( 4,14 ) ;
	a.insert ( 5,15 ) ;

	cout << "\nElements of Array: " ;
	a.display( ) ;

	a.del ( 5 ) ;
   	a.del ( 2 ) ;
	cout << "\n\nAfter deletion: " ;
	a.display( ) ;

	a.insert ( 2, 222 ) ;
	a.insert ( 5, 555 ) ;
	cout << "\n\nAfter insertion: " ;
	a.display( ) ;

	a.reverse( ) ;
	cout << "\n\nAfter reversing: " ;
	a.display( ) ;

	a.search ( 222 ) ;
	a.search ( 666 ) ;
	array b;
	b.create(10);
	b.display();
	b.sort();
	b.display();
	array c(20);
	c.merge(a,b);
	c.display();
return 0;
}