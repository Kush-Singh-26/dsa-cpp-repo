#include<bits/stdc++.h>

using namespace std;

vector<int> topo(vector<vector<pair<int, int>>>& adj, int n)
{
    vector<int> indegree(n, 0);
    for(int i=0;i<n;i++)
        for(auto e : adj[i])
            indegree[e.first]++;
    
    queue<int> q;
    for(int i = 0;i<n;i++)
        if(indegree[i] == 0)
            q.push(i);
    
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto &e : adj[node])
        {
            indegree[e.first]--;
            if(indegree[e.first] == 0)
                q.push(e.first);
        }
    }
    return ans;
}

vector<int> min_dist(vector<vector<pair<int, int>>>& adj, vector<int>& topo, int src, int n)
{
    vector<int> dist(n, INT_MAX);
    dist[src] =0;
    for(int v : topo)
    {
        if(dist[v] == INT_MAX)
            continue;
        for(auto &e : adj[v])
        {
            int node = e.first;
            int c = e.second;
            dist[node] = min(dist[node], dist[v] + c);
        }
    }

    for(int i = 0;i<n;i++)
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    return dist;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int x,y,c;
    vector<vector<pair<int,int>>>adj(n);
    for(int i =0;i<m;i++)
    {
        cin >> x >> y >> c;
        adj[x].push_back({y,c});
    }
    int src; cin >> src;

    vector<int> topo_ = topo(adj, n);
    vector<int> dist = min_dist(adj, topo_, src, n);
    for(int i : dist)
        cout << i << " ";
    cout << "\n";
    return 0;
}