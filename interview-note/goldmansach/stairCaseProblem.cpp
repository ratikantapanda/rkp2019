/* 
 * There are n stairs, a person standing at the bottom wants to reach the top. 
 * The person can climb either 1 stair or 2 or 3  stairs at a time. 
 * Count the number of ways, the person can reach the top
 * ex for 3 staris
 * countStairs(3)=4
 * 1 1 1 
 * 1 2 
 * 2 1
 *3 
 */

#include <iostream>

using namespace std;

int countStair( int n) // n=no_stair_cass
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 4;
	return countStair(n-1) + countStair(n-2) + countStair(n-3);
}

int main()
{
	cout << countStair(3) << endl;
	return 0;
}


