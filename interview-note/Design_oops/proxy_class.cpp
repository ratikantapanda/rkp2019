#include <iostream>
using namespace std;;

struct array {
    int * mPtr;
    array( int & r ) : mPtr( & r ) { std::cout << "proxy value" <<" " << *mPtr << std::endl;}
    void operator = ( int n ) 
    {
        std::cout << n << std::endl;
    	if ( n > 1 ) {
    		throw "not binary digit";
    	}
    	*mPtr = n;
    }
};

struct proxyarray {
    proxyarray()
    { 
      for(int i=0; i < 10; ++i)
      {mArray[i]=i;}
    }
    int mArray[10];
    array operator[]( int i) {return array( mArray[i] );}
};

int main() {
    try {
    	proxyarray a;
    	//a[0] = 1;	// ok
    	a[1] = 42;      // throws exception
    }
    catch( const char * e ) {
    	cout << e << endl;
    }
}
