// In an undirected graph

#include<bits/stdc++.h>

using namespace std;

bool bfs(vector<int> adj[], int src, vector<int>& vis)
{
    vis[src] = 1;

    queue<pair<int,int>> q;

    q.push({src, -1});   

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto ngb : adj[node])
        {
            if(!vis[ngb])
            {
                vis[ngb] = 1;
                q.push({ngb, node});
            }
            else if(parent != ngb)
                return true;
        }
    }
    return false;

}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for(int i =0;i<V;i++)
        if(!vis[i] && bfs(adj, i, vis)) return true;
    
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