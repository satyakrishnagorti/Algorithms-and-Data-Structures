#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

vector<vector<int> > graph;
vector<bool> visited;
vector<int> topsort;

void dfs(int v)
{
	visited[v]=true;
	for(vector<int>::iterator it = graph[v].begin();it!=graph[v].end();it++)
	{
		if(!visited[*it])
			dfs(*it);
	}
	topsort.push_back(v);
}

int main()
{
	int n,e;
	cin>>n>>e;
	visited = vector<bool> (n,0);
        graph = vector<vector<int> > (n);	
	for(int i=0;i<e;i++)
	{
		int p,q;
		cin>>p>>q;
		graph[p].push_back(q);
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			dfs(i);
	}
	reverse(topsort.begin(),topsort.end());

	//Displaying the topological sort
	cout<<"Topological ordering is: ";
	for(int i=0;i<n;i++)
		cout<<topsort[i]<<" ";
	cout<<endl;
	return 0;
}

