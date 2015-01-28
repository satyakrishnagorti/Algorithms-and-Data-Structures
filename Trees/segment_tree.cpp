// RMQ by using segment tree
#include <bits/stdc++.h>

using namespace std;
const int MAX = 8; // max size of array

int n,Tree[3*MAX];  // segment tree total nodes will be around 2Max
/**
 * function to build a segment tree
 * Initially called as build(arr,1,0,arr.size()-1)
 * @param arr    intitial array, contents of which will be in the leaves of segment tree
 * @param vertex current vertex of segment tree (index starting from 1)
 * @param low    left most array arr's index for a pirtucular instance in recursion
 * @param high   right most array arr's index for a pirticular instance in recursion
 */
void build(int arr[],int vertex,int low,int high)
{
  if(low==high){
    Tree[vertex]=arr[low];
    cout<<"Tree["<<vertex<<"]:"<<arr[low]<<endl;
  }
  else
  {
    int mid = (low+high)/2;
    build(arr,2*vertex,low,mid);               // Segment tree's left child's index: 2*v (like heap)
    build(arr,2*vertex+1,mid+1,high);          // Segment tree's right child's index: 2*v+1
    Tree[vertex] = min(Tree[2*vertex],Tree[2*vertex+1]);
    cout<<"Tree["<<vertex<<"]:"<<arr[low]<<endl;
  }
}

/**
 * queries for min within [range_left,range_right]
 * low and high are array indexes
 * @param  vertex      current vertex of segment tree
 * @param  low         left arr arrays index for an instance in recursion
 * @param  high        right arr arrays index for an instance in recursion
 * @param  range_left  left index of the range for RMQ
 * @param  range_right right index of the range for RMQ
 * @return             returns range minimum query
 */
int query(int vertex,int low,int high,int range_left,int range_right)
{
  if(range_left>high || range_right<low)
    return INT_MAX;
  if(low >= range_left && high <= range_right)
    return Tree[vertex];
  else
  {
    int mid = (low+high)/2;
    return min(query(vertex*2,low,mid,range_left,min(mid,range_right)),
              query(vertex*2+1,mid+1,high,max(mid+1,range_left),range_right));
  }
}

/**
 * updates the segment tree for a change in input arr at index with a value
 * @param vertex current vertex of segment tree
 * @param low    left arr array's index for an instance in recursion
 * @param high   right arr array's index for an instance in recursion
 * @param index  index at which arr is changed
 * @param value  new value specified at given index
 */
void update(int vertex,int low,int high,int index,int value)
{
  if(low==high){
    Tree[vertex]=value;
    return;
  }
  int mid = (low+high)/2;

  if(index<=mid)
    update(2*vertex,low,mid,index,value);
  else
    update(2*vertex+1,mid+1,high,index,value);
  Tree[vertex]=min(Tree[2*vertex],Tree[2*vertex+1]); 
}
int main()
{
  int arr[]={1,3,5,7,9,11};
  build(arr,1,0,5);

  cout<<"MIN in range[2,5]"<<query(1,0,5,2,5)<<endl;
  update(1,0,5,2,0);
  cout<<"MIN in range[2,5]"<<query(1,0,5,2,5)<<endl;
}