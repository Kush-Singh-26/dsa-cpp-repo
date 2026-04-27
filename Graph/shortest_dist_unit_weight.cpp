#include<bits/stdc++.h>

using namespace std;

vector<int> dist_func(vector<int> adj[], int n, int src)
{
    queue<int> q;
    vector<int> dist(n, INT_MAX);
    q.push(src);
    dist[src] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int v : adj[node])
        {
            if(dist[v] == INT_MAX)
            {
                dist[v] = 1 + dist[node];
                q.push(v);
            }
        }
    }

    for(int i=0;i<n;i++)
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    int x,y;
    for(int i = 0;i<m;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int src; cin >> src;
    vector<int> ans = dist_func(adj, n, src);

    for(int i : ans)
        cout << i << " ";
}