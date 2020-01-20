/* A tree is a abstract data structure consitings of nodes.
 * Each node has only one parent node and zero or more child nodes.
 * Each tree has one special node ,root.
 * A node is called a branch if it has one or more children.
 * Array p where p[i] is parent of node i.For the root node r,p[r]=-1.
 * Write a function that count the number of branches in agivean tree .
 * For example the tree represented by the array {1,3,1,-1,3} has 5 nodes, 0 to 4,
 * which two nodes are branches,only node 1 and 3 has children.
 *       3
 *      / \
 *      1  4
 *     / \
 *    0   2
 */
#include <vector>
#include <stdexcept>
#include <iostream>
#include <map>

class Branches
{
public:
    static int count(std::vector<int>& tree)
    {
	std::map<int,int> m;
	int n=0;
        if(!tree.empty())
	{
		for (const auto& e : tree) 
		{ 
			//m[e] +=1;
			++m[e];
		}
	}
	for (const auto & e : m)
	{	
    		if(e.second > 1) 
		{
			n++;
		}
	}
	return n;
    }
};


int main()
{
    std::vector<int> tree;
    tree.push_back(1);
    tree.push_back(3);
    tree.push_back(1);
    tree.push_back(-1);
    tree.push_back(3);

    std::cout << Branches::count(tree);
}
