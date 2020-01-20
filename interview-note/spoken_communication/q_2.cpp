/* You are givean two paper strips.On each strip numbers(1,2,..N) are written in a random order.
 * Cut the original paper strip into several pieces and rearange those pieces to form desired sequence.
 *
 * Write a function that written a minimum number of cut pieces needed to perform the describe operation.
 *
 * For example the following code should display three because the pieces used should be  {1},{4,3},{2}.
 *
 * std::vector<int> original = {1,4,3,2};
 * std::vector<int> desired ={1,2,4,3};
 *
 * std::cout << PaperStripMinimumPieces(original,desired) << std::endl;
 */

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>

    int minPieces(const std::vector<int>& original, const std::vector<int>& desired)
    {
	    int n=0;
	    std::map<int,int> m1;
	    for(int i=0; i < desired.size(); ++i)
	    {
		    m1[desired[i]]=i;
	    }
	    for(int i=0; i < original.size()-1; ++i)
	    {
		    if(m1[original[i+1]] != m1[original[i]]+1)
			   n++;
	    } 
            return n;
    }

#ifndef RunTests
int main()
{
    std::vector<int> original = { 1, 4, 3, 2 };
    std::vector<int> desired = { 1, 2,4,3};
    std::cout << minPieces(original, desired) << std::endl;
}
#endif
