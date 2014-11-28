#include<iostream>
#include<vector>
using namespace std;

vector<int> BIT;
int maxVal;

void init_BIT(int N)  // takes max size of BIT
{
	BIT = vector<int> (N+1,0);
	maxVal = N;
}

void update(int index,int value)
{
	while(index <= maxVal)
	{
		BIT[index] += value;
		index+=(index & -index);
	}
}
int get_cum_freq(int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=BIT[index];
		index -= (index & -index);
	}
	return sum;
}

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	init_BIT(65536);
	for(int i=0;i<10;i++)
	{
		update(i+1,array[i]);
	}

	for(int i=1;i<=10;i++)
		cout<<BIT[i]<<" ";
	cout<<endl;
	
	for(int i=0;i<10;i++)
	{
		cout<<get_cum_freq(i+1)<<" ";
	}
	cout<<endl;
	


}
