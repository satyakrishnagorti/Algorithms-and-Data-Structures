#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void max_heapify(int *heap,int i,int n)
{
	int left = 2*i+1;
	int right = 2*i+2;
	int largest;
	if(heap[left]>heap[i] && left<n)
		largest = left;
	else largest = i;

	if(heap[right]>heap[largest] && right<n)
		largest = right;

	if(largest!=i){
		swap(heap[i],heap[largest]);
		max_heapify(heap,largest,n);
	}

	/*for(int j=0;j<n;j++)
		cout<<heap[j]<<" ";
	cout<<endl;*/
}

void build_max_heap(int *heap,int n)
{
	for(int i = n/2-1;i>=0;i--){
		//cout<<"Round----------------------\n";
		max_heapify(heap,i,n);	
	}
}

int getMax(int *heap)
{
	return heap[0];
}

void slidingWindow(int *arr,int k,int n)
{
	int left = 0; int right = k-1;
	int heap[k];

	for(int i=left;i<=right;i++)
	{
		heap[i]=arr[i];
	}
	build_max_heap(heap,k);
	for(int i = k;i<n;i++)
	{
		if(arr[i]<getMax(heap)){
			heap[0]=arr[i];
			max_heapify(heap,0,k);
		}
	}

	cout<<"Smallest k numbers:";
	for(int i=0;i<k;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
}


int main()
{
	int buffer[]={7,3,9,5,1,3,4};
	slidingWindow(buffer,3,7);

}