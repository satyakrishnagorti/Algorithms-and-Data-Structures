#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/**
 * merges according to mergesorts merge technique, finds no of split inversions.
 * @param  arr   initial array
 * @param  left  left index
 * @param  mid   mid index
 * @param  right right index
 * @return       split inversion count
 */
int mergeCount(std::vector<int> &arr,int left,int mid,int right)
{
  vector<int> temp(arr.size());
  int split_inv = 0;
  int l=left,r=mid+1,k=left;
  while(l<=mid && r<=right)
  {
    if(arr[l]<arr[r]){
      temp[k]=arr[l];
      l++;k++;
    }
    else{
      temp[k]=arr[r];
      split_inv+=(mid-l+1);       // since the two subarr are sorted, in this case all the remaining elements in the 1st subarr will cause an inversion.
      r++;k++;
    }
  }
  if(r>right){
    while(l<=mid){
      temp[k]=arr[l];
      l++;k++; 
    }
  }
  else{
    while(r<=right){
      temp[k]=arr[r];
      r++;k++; 
    }
  }
  for(int i=left;i<=right;i++) arr[i]=temp[i];
  return split_inv;
}
/**
 * Using merge sort technique finds inversions in left subarr, right subarr and between left-right subarr 
 * @param  arr   initial array to compute inversions
 * @param  left  left pointer index
 * @param  right right pointer index
 * @return       no of inversions
 */ 
int mergeInversion(std::vector<int> &arr,int left,int right)
{
  if(left < right)
  {
    int mid = (left+right)/2;
    int left_inv = mergeInversion(arr,left,mid);
    int right_inv = mergeInversion(arr,mid+1,right);
    int split_inv = mergeCount(arr,left,mid,right);

    return left_inv + right_inv + split_inv;
  }
  else
    return 0;
}

int main()
{
  std::vector<int> arr;
  for(int i=0;i<10;i++)
    arr.push_back(10-i);      // no of inversions for reverse sorted arr = (n*(n-1))/2
  int inversions = mergeInversion(arr,0,arr.size()-1);
  for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";cout<<endl;
  cout<<"Inversions:"<<inversions<<endl;
} 