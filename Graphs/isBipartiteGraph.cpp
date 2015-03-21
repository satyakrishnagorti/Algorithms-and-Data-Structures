#include <bits/stdc++.h>

using namespace std;

class node{
public:
  int color;
  vector<int> neighbours;
  node(){
    color = -1;
  }
};
/**
 * checks if the given graph is bipartite. (assuming graph has single connected component)
 * @param  graph vector of nodes, where each node has a list of neighbouring vertices and a color
 * @return       return true if it is bipartite, false otherwise
 */
bool isBipartite(vector<node> graph)
{
  int start = 0;
  queue<int> q;
  q.push(start);
  while(!q.empty())
  {
    int v = q.front();
    q.pop();
    for(int i=0;i<graph[v].neighbours.size();i++)
    {
      int neigh_vertex = graph[v].neighbours[i];
      if(graph[neigh_vertex].color==-1)
      {
        graph[neigh_vertex].color=(graph[v].color+1)%2;
        q.push(neigh_vertex);
      }
      else if(graph[neigh_vertex].color==graph[v].color)
        return false;
      else continue;
    }
  }
}

int main()
{
  int n,m;
  cin>>n>>m;  //n=nodes, m=edges
  std::vector<node> graph(n);

  for(int i=0;i<m;i++)
  {
    int p,q;
    cin>>p>>q;
    graph[p].neighbours.push_back(q);
    graph[q].neighbours.push_back(p);
  }

  cout<<"Adjecency list"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<i<<"::";
    for(int j=0;j<graph[i].neighbours.size();j++)
      cout<<graph[i].neighbours[j]<<" ";
    cout<<endl;
  }

  if(isBipartite(graph))
    cout<<"Yes it is bipartite"<<endl;
  else cout<<"No not bipartite"<<endl;

}
