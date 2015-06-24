#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

    node(int N){
        data = N;
        left = NULL;
        right = NULL;
    }
};

int height(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return 1+max(height(root->left),height(root->right));
}

int DiameterTree(struct node * root){
    int left_height=0,right_height=0;

    if(root==NULL)
        return 0;

    left_height = height(root->left);
    right_height = height(root->right);

    int diameter_left = DiameterTree(root->left);
    int diameter_right = DiameterTree(root->right);

    int max_dia = max(diameter_left,diameter_right);
    return max( left_height+right_height+1 ,max(diameter_left,diameter_right));

}

int main()
{
    struct node * root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);

    cout<<"Diameter: "<<DiameterTree(root);

    return 0;
}
