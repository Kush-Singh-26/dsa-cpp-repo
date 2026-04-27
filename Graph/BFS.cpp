#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int V, vector<int> adj[])
{
    vector<int> vis(V+1, 0);
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
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

    vector<int> bfs = BFS(n, adj);
    cout << "BFS\n";
    for(int i= 0;i<bfs.size();i++)
        cout << bfs[i] << " ";
    
    cout << "\n";

    return 0;
}
