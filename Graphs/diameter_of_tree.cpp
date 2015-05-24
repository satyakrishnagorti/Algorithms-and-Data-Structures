#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> visited;

int n,long_node;
int dist=0;

pair<int,int> dfs(int u)
{
        stack<int> S;
        visited[u]=1;
        long_node = u;
        dist = 0;
        S.push(u);
        while(!S.empty())
        {
            int v = S.top();

            bool flag = false;

            for(vector<int>::iterator it=graph[v].begin();it!=graph[v].end();it++)
            {
                if(!visited[*it])
                {
                    flag = true;
                    S.push(*it);
                    visited[*it]=true;
                    break;
                }
            }

            if(S.size()>dist)
            {
                dist=S.size();
                long_node = S.top();
            }
            if(!flag)
                S.pop();
        }

        return make_pair(long_node,dist-1);

}

int main()
{
    cin>>n;
    graph = vector<vector<int> >(n);
    visited = vector<int>(n,0);

    for(int i=0;i<n-1;i++)
    {
            int p,q;
            cin>>p>>q;
            p--;q--;
            graph[p].push_back(q);
            graph[q].push_back(p);
    }

    pair<int,int> p = dfs(0);

    int long_node = p.first;

    visited = vector<int>(n,0);

    pair<int,int> q = dfs(long_node);

    cout<<q.second<<endl;

}
