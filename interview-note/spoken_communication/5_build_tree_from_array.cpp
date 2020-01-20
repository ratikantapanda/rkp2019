#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = nullptr; 
	node->right = nullptr;

	return node;
}

// Function to perform inorder traversal of the tree
void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void preeorder(Node* root)
{
	if(root == nullptr)
		return;
	 cout << root->data << " ";
	 preeorder(root->left);
	 preeorder(root->right);
}
void postorder(Node* root)
{
	if(root == nullptr)
		return;
	 preeorder(root->left);
	 preeorder(root->right);
	 cout << root->data << " ";
}
// non leaf Nodes
int countBranch(Node* root)
{
     if(root == nullptr ||( (root->left==nullptr) && (root-> right==nullptr)))
	     return 0;
     return 1 + countBranch(root->left) + countBranch( root->right);
}


// Function to build the tree from given parent array
Node *createTree(int parent[], int n)
{
    // create an empty map
	//unordered_map<int, Node*> map;
	std::map<int, Node*> m;

	// create n new tree nodes each having value from 0 to n-1
	// and store them in a map
	for (int i = 0; i < n; i++)
		m[i] = newNode(i);

    // represents root node of binary tree
	Node *root = nullptr;

	// traverse the parent array and build the tree
	for (int i = 0; i < n; i++)
	{
	    // if parent is -1, set root to current node having
	    // value i (stored in map[i])
		if (parent[i] == -1)
			root = m[i];
		else
		{
		    // get parent node for current node
			Node *parentPtr = m[parent[i]];

			// if parent's left child is filled, map the node to its right child
			if (parentPtr->left)
				parentPtr->right = m[i];

			// if parent's left child is empty, map the node to it
            else
				parentPtr->left = m[i];
		}
	}

	// return root of the constructed tree
	return root;
}

// main function
int main()
{
	int parent[] = {-1, 0, 0, 1, 2, 2, 4, 4};
	int n = sizeof parent / sizeof parent[0];

	Node *root1 = createTree(parent, n);

	inorder(root1);
	cout<<'\n';
	preeorder(root1);
	cout<<'\n';
	postorder(root1);
	cout<<'\n';
	int arr1[]={1,3,1,-1,3};
	Node* root2=createTree(arr1,5);
	inorder(root2);
	cout<<'\n';
	preeorder(root2);
	cout<<'\n';
	cout << countBranch(root2) << endl;

	return 0;
}
