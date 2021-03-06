// Tree_C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data) {
struct node* node = new(struct node); // "new" is like "malloc"
node->data = data;
node->left = NULL;
node->right = NULL;
return(node);
}



struct node* insert(struct node* node, int data) {
if (node == NULL) {
return(newNode(data));
}
else {
if (data <= node->data) node->left = insert(node->left, data);
else node->right = insert(node->right, data);
return(node);
}
}


int size(struct node* node) {
if (node==NULL) {
return(0);
} else {
	int leftSize=size(node->left);
	int rightSize=size(node->right);
return(leftSize + 1 + rightSize);
}
}

int maxDepth(struct node* node) {
if (node==NULL) {
return(0);
}
else {
int lDepth = maxDepth(node->left);
int rDepth = maxDepth(node->right);
if (lDepth > rDepth) return(lDepth+1);
else return(rDepth+1);
}
}

void printTree(struct node* node) {
if (node == NULL) return;
printTree(node->left);
printf("%d ", node->data);
printTree(node->right);
}

void printPostorder(struct node* node) {
if (node == NULL) return;
printTree(node->left);
printTree(node->right);
printf("%d ", node->data);

}
void printPreeorder(struct node* node){
if(node==NULL) return;
printf("%d ", node->data);
printTree(node->left);
printTree(node->right);
}
int hasPathSum(struct node* node, int sum) {
if (node == NULL) {
return(sum == 0);
}
else {
// otherwise check both subtrees
int subSum = sum - node->data;
return(hasPathSum(node->left, subSum) ||
hasPathSum(node->right, subSum));
}
}
	
int minValue(struct node* node) {
struct node* current = node;
while (current->left != NULL) {
current = current->left;
}
return(current->data);
}
int maxValue(struct node* node) {
struct node* current = node;
while (current->right != NULL) {
current = current->right;
}
return(current->data);
}
void mirror(struct node* node) {
if (node==NULL) {
return;
}
else {
struct node* temp;
// do the subtrees
mirror(node->left);
mirror(node->right);
// swap the pointers in this node
temp = node->left;
node->left = node->right;
node->right = temp;
}
}

int isBST(struct node* node) {
if (node==NULL) return(true);
// false if the min of the left is > than us
if (node->left!=NULL && minValue(node->left) > node->data)
return(false);
// false if the max of the right is <= than us
if (node->right!=NULL && maxValue(node->right) <= node->data)
return(false);
// false if, recursively, the left or right is not a BST
if (!isBST(node->left) || !isBST(node->right))
return(false);
// passing all that, it's a BST
return(true);
}

// Utility that prints out an array on a line.
void printArray(int ints[], int len) {
int i;
for (i=0; i<len; i++) {
printf("%d ", ints[i]);
}
printf("\n");
}
/*
Recursive helper function -- given a node, and an array containing
the path from the root node up to but not including this node,
print out all the root-leaf paths.
*/
void printPathsRecur(struct node* node, int path[], int pathLen) {
if (node==NULL) return;
// append this node to the path array
path[pathLen] = node->data;
pathLen++;
// it's a leaf, so print the path that led to here
if (node->left==NULL && node->right==NULL) {
printArray(path, pathLen);
}
else {
// otherwise try both subtrees
printPathsRecur(node->left, path, pathLen);
printPathsRecur(node->right, path, pathLen);
}
}
/*
Given a binary tree, print out all of its root-to-leaf
paths, one per line. Uses a recursive helper to do the work.
*/
void printPaths(struct node* node) {
int path[1000];
printPathsRecur(node, path, 0);
}
struct node* LCA(struct node* root,int a, int b){
	if(root ==NULL){
		return NULL;
	}
		if( (root->data == a) || (root->data == b) ){
			return root;
		}
		struct node* l=LCA(root->left,a,b);
		struct node* r=LCA(root->right,a,b);
		if( 1!=NULL && r!=NULL ){
			return root;
		}
		return (l!=NULL ? l: r );
	}
void doubleTree(struct node* node) {
struct node* oldLeft;
if (node==NULL) return;
// do the subtrees
doubleTree(node->left);
doubleTree(node->right);
// duplicate this node to its left
oldLeft = node->left;
node->left = newNode(node->data);
node->left->left = oldLeft;
}
int sameTree(struct node* a, struct node* b) {
// 1. both empty -> true
if (a==NULL && b==NULL) return(true);
// 2. both non-empty -> compare them
else if (a!=NULL && b!=NULL) {
return(
a->data == b->data &&
sameTree(a->left, b->left) &&
sameTree(a->right, b->right)
);
}
// 3. one empty, one not -> false
else return(false);
}

int countTrees(int numKeys) {
if (numKeys <=1) {
return(1);
}
else {
// there will be one value at the root, with whatever remains
// on the left and right each forming their own subtrees.
// Iterate through all the values that could be the root...
int sum = 0;
int left, right, root;
for (root=1; root<=numKeys; root++) {
left = countTrees(root - 1);
right = countTrees(numKeys - root);
// number of possible trees with this root == left*right
sum += left*right;
}
return(sum);
}
}
int main(int argc, _TCHAR* argv[])
{  struct node* root = NULL;
root = insert(root, 2);
root = insert(root, 1);
root = insert(root, 3);
printTree(root);
printf("\n");
printPostorder(root);
printf("\n");
printPreeorder(root);
printf("\n");
printPaths(root);
printf("\n");
struct node* tempnodeptr=LCA(root,1,4);
printf("%d",tempnodeptr->data);
	return 0;
}

