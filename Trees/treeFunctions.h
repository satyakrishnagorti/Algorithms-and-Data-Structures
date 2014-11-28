#include <iostream>
#include <limits.h>
#include <queue>
#include <stack>
#include <utility>
#include "treeNode.h"

using namespace std;

int findMax(node *root){
	int max_value = INT_MIN,leftMax,rightMax;

	if(root){
		int root_val = root->data;
		leftMax=findMax(root->left);
		rightMax=findMax(root->right);
		if(leftMax<rightMax)
			max_value=rightMax;
		else max_value=leftMax;

		if(root_val>max_value)
			max_value=root_val;
	}
	return max_value;

}

int treeSize(node *root){

	if(root==NULL)
		return 0;
	else{

		return 1+treeSize(root->left)+treeSize(root->right);
	}

}

void bfsNode(node *root){
	queue<node *> qu;
	qu.push(root);
	while(!qu.empty())
	{
		node * p = qu.front();
		cout<<p->data<<" ";
		qu.pop();
		if(p->left)
			qu.push(p->left);
		if(p->right)
			qu.push(p->right);
	}
}

int totalLeaves(node *root){
	int no_leaves;
	if(root){
		if(root->left==NULL && root->right==NULL)
			return 1;
		else{
			no_leaves = totalLeaves(root->left)+totalLeaves(root->right);
		}
	}
	else
        return 0;
	return no_leaves;
}

int checkSameTree(node *root1,node *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    return(root1->data==root2->data && checkSameTree(root1->left,root2->left) && checkSameTree(root1->right,root2->right));

}

vector<int> levelSum(node *root){

	std::vector<int> v(10,0);
	queue<pair<node *,int> > qu;

	qu.push(make_pair(root,0));

	while(!qu.empty()){

		node * p = qu.front().first;
		int node_level =  qu.front().second;
		qu.pop();

		v[node_level]+=p->data;

		if(p->right)
			qu.push(make_pair(p->right,node_level+1));
		if(p->left)
			qu.push(make_pair(p->left,node_level+1));
	}
	return v;
}

void printPath(int path[],int length)                 //Utility function to print current root-leaf path used by printrootToLeafPaths() 
{
	for(int i=0;i<length;i++)
		cout<<path[i]<<" ";
	cout<<endl;
}

void printrootToLeafPaths(node *root,int path[],int length){

	if(root==NULL)
		return;
	else{
		path[length]=root->data;
		length++;

		if(root->left==NULL && root->right==NULL)
			printPath(path,length);
		else{
			printrootToLeafPaths(root->left,path,length);
			printrootToLeafPaths(root->right,path,length);
		}
	}
}


