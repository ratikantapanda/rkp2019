#include <stdio.h>
#include <iostream>

using namespace std;

void swap(int& a,int& b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}

bool isEven(int n)
{
	return ((n &1)==0);
}

//check a number is power of 2 or not
//n &(n-1) if 0 ,it is power of 2
//or if (n & -n == n)

bool isPowerOf2(int n)
{
	return (n &(n-1)==0);
}
//unset the rightmost bit of a number

int unsetRightMostBit(int n)
{
	return n & (n-1);
}
// Find position of the rightmost set bit

int findPositionOfRightMostSetBit(int n)
{
	int result= n&(n-1);
	return result ^ n;
	//or return (n & -n);
}

int multiplyBy2(int n)
{
	return n << 1;
	//multiply by 4 i.e n<< 2
	//multiply by 16 i.e n <<4
}
int divissionBy2(int n)
{
	return n>>1;
}

int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
 //  Check if a given Bit Position is set to 1 or not
 bool checkBitPosFlag(unsigned int  n, unsigned  pos)
{
	int result= n >> pos;
	return (result & 1);
}
int isKthBitset(int n,int k)
{
	return n & ( 1 << (k-1));
}
int turnOffKthBit(int n,int k)
{
	return n & ~(1<<(k-1));
}
int turnOnKthBit(int n,int k)
{
	return n | (1<<(k-1));
}

//Toggle the kth bit
int toggleKthBit(int n, int k)
{
	return n ^ ( 1 <<(k-1));
}

//detect if two integers have opposite signs

int x, y;               // input values to compare signs
bool f = ((x ^ y) < 0); // true iff x and y have opposite signs

/*//Compute the integer absolute value (abs) without branching.

int v;           // we want to find the absolute value of v
unsigned int r;  // the result goes here
int const mask = v >> sizeof(int) * CHAR_BIT - 1;
r = (v + mask) ^ mask;
*/

/*Compute the minimum (min) or maximum (max) of two integers without branching.

int x;  // we want to find the minimum of x and y
int y;
int r;  // the result goes here
r = y ^ ((x ^ y) & -(x < y)); // min(x, y)
r = x ^ ((x ^ y) & -(x < y)); // max(x, y)
*/

/*Counting bits set, Brian Kernighan's way

unsigned int v; // count the number of bits set in v
unsigned int c; // c accumulates the total bits set in v
for (c = 0; v; c++)
{
  v &= v - 1; // clear the least significant bit set
}
*/

/*Reverse bits.

unsigned int v;     // input bits to be reversed
unsigned int r = v; // r will be reversed bits of v; first get LSB of v
int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end
for (v >>= 1; v; v >>= 1)
{   
  r <<= 1;
  r |= v & 1;
  s--;
}
r <<= s; // shift when v's highest bits are zero
*/

/*Determining if an integer is a power of 2.

unsigned int v;     // we want to see if v is a power of 2 bool f; 
f = v && !(v & (v - 1));
*/

/*
 * float Q_rsqrt( float number ){
        long i;
        float x2, y;
        const float threehalfs = 1.5F;
        x2 = number * 0.5F;
        y  = number;
        i  = * ( long * ) &y;                       // evil floating point bit level hacking
        i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
        return y;
}*/


int main()
{
	std::cout << checkBitPosFlag(5,3) << std::endl;

}
