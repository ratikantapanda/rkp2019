#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;
}

// Function to insert given key into the tree
void insert(Node*& root, string level, int key)
{
	// tree is empty
	if (level.length() == 0)
	{
		root = newNode(key);
		return;
	}

	int i = 0;
	Node* ptr = root;
	while (i < level.length() - 1)
	{
		if (level[i++] == 'L')
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	if (level[i] == 'L')
		ptr->left = newNode(key);
	else
		ptr->right = newNode(key);
}

// Function to find next node for given node  in same level in a binary tree
// by using pre-order traversal
Node* findRightNode(Node* root, int value, int level, int &value_level)
{
    // return null if tree is empty
    if (root == nullptr)
		return nullptr;

    // if desired node is found, set value_level to current level
	if (root->key == value)
	{
		value_level = level;
		return nullptr;
	}

	// if value_level is already set, then current node is the next right node
	else if (value_level)
	{
		if (level == value_level)
			return root;
	}

    // recurse for left subtree by increasing level by 1
	Node* left = findRightNode(root->left, value, level + 1, value_level);

	// if node is found in left subtree, return it
	if (left)
		return left;

    // recurse for right subtree by increasing level by 1
	return findRightNode(root->right, value, level + 1, value_level);
}

// Function to find next node of given node in the same level
// in given binary tree
Node* findRightNode(Node* root, int value)
{
	int value_level = 0;

	return findRightNode(root, value, 1, value_level);
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below Tree
	          1
	        /  \
	       /    \
	      2      3
	     / \      \
	    4   5      6
	              / \
                 7   8
	*/
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5},
		{"RL", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    Node *right = findRightNode(root, 5);
	if (right)
        cout << "Right Node is " << right->key;
	else
        cout << "Right Node doesn't exists";

	return 0;
}
