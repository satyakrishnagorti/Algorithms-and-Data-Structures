#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

vector<bool> visited;
vector<vector<int> > gf,gb;
vector<int> components,order;
int no_SCC=0;

void dfs1(int i)
{
	visited[i]=true;
	for(vector<int>::iterator it=gf[i].begin();it!=gf[i].end();it++){
		if(!visited[*it])
			dfs1(*it);
	}	
	order.push_back(i);
}

void dfs2(int i)
{
	visited[i]=true;
	components.push_back(i);
	for(vector<int>::iterator it=gb[i].begin();it!=gb[i].end();it++)
		if(!visited[*it])
			dfs2(*it);
}

int main()
{
	int n,e;
	cin>>n>>e;
	gf = vector<vector<int> > (n);
	gb = vector<vector<int> > (n);
	for(int i=0;i<e;i++)
	{
		int p,q;
		cin>>p>>q;
		gf[p].push_back(q);
		gb[q].push_back(p);
	}
	visited = vector<bool> (n,0);
	for(int i=0;i<n;i++)
		if(!visited[i])
			dfs1(i);
	visited.assign(n,0);

	for(int i=0;i<n;i++)
	{
		int v = order[n-1-i];
		if(!visited[v])
			dfs2(v);
		// SCC stored in components;
		components.clear();

	}
}
