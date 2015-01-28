#include <bits/stdc++.h>
using namespace std;

struct Interval
{
  int low,high;
};

struct int_tree_node{
  Interval it;
  int_tree_node * left, *right;
  int maxValue;
};

int_tree_node * newNode(Interval it)
{
  int_tree_node *node = new int_tree_node;
  node->it = it;
  node->left = NULL;
  node->right = NULL;
  node->maxValue = it.high;
}

int_tree_node * insert(int_tree_node *root,Interval it)
{
  if(root==NULL)
    return newNode(it);
  if((root->it.low) > (it.low))
    root->left = insert(root->left,it);
  else
    root->right = insert(root->right,it);

  if(root->maxValue< it.high)
    root->maxValue=it.high;

  return root;
}

bool ifIntersects(Interval it1,Interval it2)
{
  return (it1.low<=it2.high && it2.low <= it1.high);
}

Interval *search(int_tree_node *root,Interval it)
{
  if(root==NULL)
    return NULL;
  if(ifIntersects((root->it),it)){
    //return root->it;
    Interval *i = new Interval;
    *i = root->it;
    return  i;
  }
  if(root->left!=NULL && root->left->maxValue>it.low)
  {
    return search(root->left,it);
  } 
  return search(root->right,it);
}

void inOrderTraversal(int_tree_node *root){
  if(root==NULL) return;

  inOrderTraversal(root->left);
  cout<<"{"<<root->it.low<<","<<root->it.high<<"}"<<":max:"<<root->maxValue<<endl;
  inOrderTraversal(root->right);
}

int main()
{
  Interval it[]= {{15, 20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {30, 40}};
  int_tree_node *root = NULL;
   for (int i = 0; i < 6; i++)
        root = insert(root, it[i]);
  inOrderTraversal(root);
  Interval it1 = {35,45};
  Interval *res = search(root,it1);
  if(res==NULL)
    cout<<"No such interval"<<endl;
  else
    cout<<"Overlaps with interval:{"<<res->low<<","<<res->high<<"}"<<endl;
  return 0;
}