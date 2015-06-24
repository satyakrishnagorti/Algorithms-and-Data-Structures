// Problem: Given a bitonic array search an element in O(nlogn) time

#include<bits/stdc++.h>
using namespace std;
int middle_binoic(int arr[],int left, int right)
{
	while((right-left)>1)
	{
		int mid = left + (right-left)/2;
		if(arr[mid]>arr[mid+1]){
			right = mid;

		}
		else{
			left = mid;
		}
	}
	return left+1;
	
}

int main()
{
	int arr[]={1,2,3,4,5,6,5,4,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int mid = middle_binoic(arr,0,n-1);
	cout<<"Middle element index:"<<mid<<" value:"<<arr[mid]<<endl;
	// now can search on the left side and right side of middle element using normal binary search
	return 0;
}
