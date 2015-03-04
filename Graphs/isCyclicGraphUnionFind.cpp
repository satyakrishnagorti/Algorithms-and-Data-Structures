#include <bits/stdc++.h>

using namespace std;

int parent[100];

int find(int i)
{
  while(i!=parent[i])
    i=parent[parent[i]];     // Faster Climbing :P
  return i;
}

void Union(int i,int j)
{
  int x = find(i);
  int y = find(j);
  parent[x]=y;
}

bool isCyclic(vector<pair<int,int> > edges)
{
  for(auto it=edges.begin();it!=edges.end();it++)
  {
    if(find(it->first)==find(it->second))
      return true;
    Union(it->first,it->second);
  }
  return false; 
}

int init(int n)
{
  for(int i=0;i<n;i++)
    parent[i]=i;
}

int main()
{
  int n,m;
  cin>>n>>m; //no of vertices and edges
  vector<pair<int,int> > edges;
  init(n);
  for(int i=0;i<m;i++)
  {
    int p,q;
    cin>>p>>q;
    edges.push_back(make_pair(p,q));
  }
  if(isCyclic(edges))
    cout<<"Yes"<<endl;
  else cout<<"NO"<<endl;

}