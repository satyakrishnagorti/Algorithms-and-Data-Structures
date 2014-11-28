#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node{

int data;
node *left;
node *right;

};

node * createNode(int value){

	node *root = new node;
	root->data = value;
	root->right = NULL;
	root->left = NULL;
	return root;
}

void preOrder(node *root){

	if(root!=NULL){

		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(node *root){
	if(root){

		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void inOrder(node *root){
	if(root){

		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

node * insertNode(node *root,int data){
	if(root==NULL){
		//root=createNode(data);
		//cout<<"\nInserted:"<<(root)->data<<endl;
		return createNode(data);
	}
	else if(data<=root->data){
		root->left=insertNode((root->left),data);
	}
	else{
		root->right=insertNode((root->right),data);
	}
	return root;
}
