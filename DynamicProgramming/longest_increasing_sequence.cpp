#include <iostream>
#include <algorithm>
using namespace std;

int lis(int *arr,int n)
{
  int DP[n+1];
  for(int i=0;i<n;i++)
    DP[i]=1;

  for(int i=1 ;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(arr[i]>arr[j] && DP[i]<DP[j]+1)
        DP[i]=1+DP[j];
    }
  }
  int max=1;
  for(int i=0;i<n;i++)
    if(max<DP[i])
      max=DP[i];
  cout<<"LIS lenght:"<<max;
  return max;
}


int main()
{
  int arr[]={10, 22, 9, 33, 21, 50, 41, 60, 80};
  lis(arr,sizeof(arr)/sizeof(int));
}