#include <bits/stdc++.h>
using namespace std;

void DFS(int v, vector<int> adj[], vector<int>& vis, vector<int>& res)
{
    vis[v] = 1;

    res.push_back(v);

    for(int x : adj[v])
    {
        if(!vis[x])
            DFS(x, adj, vis, res);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i =0;i<m;i++)
    {   
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j : adj[i])
            cout << j << " ";
        cout << "\n";
    }

    vector<int> dfs;
    vector<int> vis(n+1, 0);
    DFS(1,adj, vis, dfs);
    cout << "DFS\n";
    for(int i= 0;i<dfs.size();i++)
        cout << dfs[i] << " ";
    
    cout << "\n";

    return 0;
}
