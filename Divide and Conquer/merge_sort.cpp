#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr,int left,int mid,int right)
{
  std::vector<int> c(arr.size());
  int l = left;
  int r = mid+1;
  int k=left;
  while(l <= mid && r <= right)
  {
    if(arr[l]<arr[r]){
      c[k]=arr[l]; 
      l++;
      k++;
    }
    else{
      c[k]=arr[r];
      r++;
      k++;
    }
  }
  if(r > right){
    while(l <= mid){
        c[k]=arr[l]; 
        l++;
        k++;
    }
  }
  else{
    while(r <= right){
      c[k]=arr[r];
      r++;
      k++;
    }
  }

  for(int i=left;i<=right;i++)  
    arr[i]=c[i];
}

void mergeSort(vector<int> &arr,int left,int right)
{
  if(left < right)
  {
    int mid = (left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
  }
}
int main()
{
  std::vector<int> arr;
  for(int i=0;i<10;i++)
  {
    arr.push_back(10-i);
  }
  mergeSort(arr,0,arr.size()-1);
  for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
  cout<<endl;

}