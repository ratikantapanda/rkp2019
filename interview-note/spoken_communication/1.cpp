#include <iostream>
#include <string>
#include <vector>
using namespace std;

     1 -> null

  2  ->  3 -> null

4 ->  5 ->  6 ->  7 -> null

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* adjacent;
    Node(int _data): data(_data),left(nullptr),right(nullptr),adjacent(nullptr){}
};
void process_tree(Node* root)
{
    if(root==nullptr)
    {
        return;
    }
    if(root->left && root->right)
    {
        (root->left)->adjacent=root->right;
    }
    if(root->left->right !=nullptr  && root->right->left != nullptr)
    process_tree(root->left);
    process_tree(root->right);

}




long  long fact(int n)
{
    if( n >= 0)
    {
        if(n==0 || n==1)
        {
          return 1;
        }
        return n* fact(n-1);
    }
    else 
    {
        return 1;
    }
}

int main()
{
	std::cout << "Hello world - C++ !" << endl;
	return 0;
}

