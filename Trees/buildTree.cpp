#include <iostream>
#include <algorithm>
#include <vector>
#include "treeFunctions.h"

using namespace std;


int main(){

	int node_values[]={7,1,3,5,12,45,0};
	node * root=NULL;
	root = insertNode(root,6);   // hardcoding the root value as 6
	for(int i:node_values)
	{
		root = insertNode(root,i);
	}

	/* making another tree with the same values */
	/********************************************/
	node * root1=NULL;
	root1 = insertNode(root1,5);   // hardcoding the root value as 6
	for(int i:node_values)
	{
		root1 = insertNode(root1,i);
	}

	cout<<"preOrder:";
	preOrder(root);
	cout<<endl;
	cout<<"inOrder:";
	inOrder(root);
	cout<<endl;


	cout<<"Max Value:"<<findMax(root)<<endl;

	cout<<"Tree Size:"<<treeSize(root)<<endl;

	cout<<"Level Order Traversal:"; bfsNode(root); cout<<endl;

	cout<<"No of leaves:"<<totalLeaves(root)<<endl;

	cout<<"Checking the two trees:"<<checkSameTree(root,root1)<<endl;


	std::vector<int> v=levelSum(root);

	for(int i=0;i<4;i++)                 // since sample tree height is 4 :P
	{
		cout<<"Level sum "<<i<<" : "<<v[i]<<endl;	
	}
	int path[10];

	cout<<"Root to Leaf Paths:\n";	
	printRootToLeafPaths(root, path, 0);
}


