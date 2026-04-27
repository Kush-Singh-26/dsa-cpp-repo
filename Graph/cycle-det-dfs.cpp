// In an undirected graph

#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis)
{
    vis[node] = 1;
    for(int ngb : adj[node])
    {
        if(!vis[ngb]){
            if(dfs(ngb, node, adj, vis))
                return true;
        }
        else if(ngb != parent)
            return true;
    }

    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for(int i =0;i<V;i++)
        if(!vis[i] && dfs(i, -1, adj, vis)) return true;
    
        return false;
}

int main()
{
    // int n,m;
    // cin >> n >> m;

    // vector<int> adj[n];
    // for(int i = 0;i<m;i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     adj[x].push_back(y);
    //     adj[y].push_back(x);
    // }

    vector<int> adj[4];
    adj[1] = {2};
    adj[2] = {1,3};
    adj[3] = {2};

    cout << isCyclic(4, adj);

    return 0;
}