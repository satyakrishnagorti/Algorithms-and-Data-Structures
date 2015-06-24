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

int CheckPathSum(struct node * root,int sum)
{
    if(root==NULL)
        return sum==0;
    else{
        int remaining_sum = 0;
        remaining_sum=sum - root->data;
        cout<<"SUM:"<<sum<<" remaining_sum:"<<remaining_sum<<" node:"<<root->data<<endl;
        if(root->left && root->right)
            return CheckPathSum(root->left, remaining_sum)||CheckPathSum(root->right,remaining_sum);

        else if(!root->left && !root->right)
            return 0 == remaining_sum;

        else if(root->left)
            return CheckPathSum(root->left,remaining_sum);

        else return CheckPathSum(root->right,remaining_sum);
    }
}

int main()
{
    struct node * root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);

    if(CheckPathSum(root,18))
      cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
