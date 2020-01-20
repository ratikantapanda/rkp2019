 
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
  
  if(root->left==nullptr && root->right==nullptr)
  {
    return;
  }
 
  if(root->left != nullptr && root->right != nullptr)
  {
    root->left->adjacentt=root->right; //This is requiredment
 
    Node* tmp = root->adjacent;
    /* Find the first node's first child in root's level */
    while(tmp!=nullptr)
    {
      if( tmp->left==nullptr)
      {
         root->right->adjacent=tmp->left;
      }
      if( tmp->right==nullptr)
      {
         root->right->adjacent=tmp->right;
      }
      tmp = tmp->adjacent;
    }
    if(tmp==nullptr)
    {
      root->right->adjacent=nullptr;
    }
  }
  else if(root->left==nullptr)
  {
    Node* tmp = root->adjacent;
    while(tmp!=nullptr && tmp->adjacent !=nullptr && tmp->adjacent->left ==nullptr && tm->adjacent->right==nullptr)
    {
      if(tmp->left !=nullptr)
      {
        root->right->adjacent=tmp->left;
      }
      if(tmp->right != nullptr)
      {
        root->right->adjacent=tmp->right;
      }
      tmp = tmp->adjacent;
    }
 
    if(tmp==nullptr)
    {
      root->right->adjacent=nullptr;
    }
  } 
  else
  {
    Node* tmp = root->adjacent;
    while(tmp!=nullptr && tmp->left ==nullptr && tmp->right==nullptr)
    {
      tmp = tmp->adjacent;
    }
 
    if(tmp==nullptr)
    {
      root->left->adjacent=nullptr;
    }
    else if(tmp->left!=nullptr)
    { 
      root->left->adjacent=tmp->left;
    }
    else if(tmp->right!=nullptr)
    {  
      root->left->adjacent=tmp->right;
    }
  }
  process_tree(root->left);
  process_tree(root->right);
}

