#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int> arr)
{
	int n=arr.size(),flag=0;
	
	//To check if all are negative, if so return most positive no from these negative nos
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=0){
			flag=1;
			break;
		}
	}
	if(!flag)
		return *max_element(arr.begin(),arr.end());

	int max_ending_here=0,max_so_far=0;
	for(int i=0;i<n;i++)
	{
		max_ending_here=max(0,max_ending_here+arr[i]);
		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;

	}
	return max_so_far;
}

int main()
{
	vector<int> arr {-2,-3,4,-1,-2,1,5,-3};
	cout<<"Max Sub array is:"<<maxSubArray(arr)<<endl;
	return 0;
}

