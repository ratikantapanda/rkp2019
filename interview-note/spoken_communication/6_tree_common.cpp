#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node
{
	int data;
	Node *left, 
        Node  *right;
	Node(int key):data(key),left(nullptr),right(nullptr){}
};


// Recursive function to insert an key into BST
Node* insert(Node* root, int key)
{
	if (root == nullptr)
		return (new Node(key));
	if (key < root->data)
	{
		root->left = insert(root->left, key);
	}

        else
	{
		root->right = insert(root->right, key);
	}

	return root;
}

bool isBST(Node* node, int minKey, int maxKey)
{
    if (node == NULL)
        return true;

    if (node->data < minKey || node->data > maxKey)
        return false;

    // recursively check left and right subtrees with updated range
    return isBST(node->left, minKey, node->data) &&
            isBST(node->right, node->data, maxKey);
}

// Function to determine if given Binary Tree is a BST or not
void isBST(Node* root)
{
	if(isBST(root, INT_MIN, INT_MAX))
        printf("This is a BST.");
    else
        printf("This is NOT a BST!");
}
// Function to perform inorder traversal of the tree
void inorder(Node* root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// main function
int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// swap nodes
	swap(root->left, root->right);
	isBST(root);

	return 0;
}
