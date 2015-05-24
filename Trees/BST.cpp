#include <bits/stdc++.h>

using namespace std;

struct node{
  int data;
  node * left;
  node * right;
  node()
  {
    left = NULL;
    right = NULL;
  }
  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

node * findNode(node * root,int val)
{
  if(root==NULL) return NULL;
  while(root->data!=val)
  {
    if(val<root->data)
      root=root->left;
    else
      root=root->right;
  }
  return root;
}

node * findMin(node * root)
{
  if(root==NULL)
    return NULL;
  while(root->left!=NULL)
    root=root->left;
  return root;
}

node * getSuccessor(node * root, int data)
{
  
  node * current = findNode(root,data);
  if(current==NULL) return NULL;

  //case 1: right subtree of node present

  if(current->right!=NULL)
    return findMin(current->right);

  //case 2: right subtree not present

  else{
    node * successor,*ancestor;
    successor = NULL; 
    ancestor = root;

    while(current!=ancestor){
      if(current->data<ancestor->data){
        successor = ancestor;
        ancestor = ancestor->left;
      }
      else{
        ancestor = ancestor->right;
      }
    }
    return successor;
  }
}

node * insertBST(node *root,int data)
{
  if(root==NULL){
    root = new node(data);
    return root;
  }
  else{
    if(data < root->data){
      if(root->left==NULL)
        root->left = new node(data);
      else
        root->left = insertBST(root->left,data);
    }
    else{
      if(root->right==NULL)
        root->right = new node(data);
      else
        root->right = insertBST(root->right,data);
    }
  }
  return root;
}

void preorder(node *root)
{
  if(root)
  {
    cout<<"Node value:"<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(node *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    cout<<"Node value:"<<root->data<<endl;
    inorder(root->right);
  }
  else return;
}

void insertHelper(node *root)
{
  insertBST(root,10);
  insertBST(root,8);
  insertBST(root,6);
  insertBST(root,12);
  insertBST(root,11);
  insertBST(root,20);
  insertBST(root,17);
  insertBST(root,25);
}

int main()
{
  node * root=NULL;
  cout<<"hello"<<endl;
  root = insertBST(root,15);
  insertHelper(root);
  //inorder(root);
  preorder(root);

  node * temp = getSuccessor(root,6);
  cout<<"successor is:"<<temp->data<<endl;
}