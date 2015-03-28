#include<bits/stdc++.h>
using namespace std;

pair<int,int> find_max_subarray(const vector<int> &A)
{
	//returns a pair range; range.first and range.second(including)  will be the boundaries for max_subarray
	// Let S[i] be sum to first i elements;
	// Have to maximize S[j] - S[i] where i<=j to get max subarray;
	
	int sum =0, min_index = -1, max_index = 0, min_sum = 0, max_sum = INT_MIN;
	for(int i=0;i<A.size();i++)
	{
		sum+=A[i];
		if(sum<min_sum)
		{
			min_sum = sum;
			min_index = i;
		}
		if(sum - min_sum > max_sum){
			max_sum = sum-min_sum;
			max_index = i;
		}
	}
	pair<int,int> range = make_pair(min_index+1,max_index);
	cout<<"Max Sub Array:"<<max_sum<<endl;
	return range;
}

int main()
{
	vector<int> A;
	int n,x,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		A.push_back(x);
	}
	pair<int,int> range = find_max_subarray(A);

	cout<<"min index:"<<range.first<<"\nmax_index:"<<range.second<<endl;
}
