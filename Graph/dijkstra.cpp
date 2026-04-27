#include<bits/stdc++.h>
using namespace std;

vector<int> dijsktra(vector<vector<pair<int, int>>>& adj, int n, int src)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    // {dist from src, node}, min-heap
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d > dist[node])
            continue;
        
        for(auto v : adj[node])
        {
            int next = v.first;
            int c = v.second;
            if(dist[node] + c < dist[next])
            {
                dist[next] = dist[node] + c;
                pq.push({dist[next], next});
            }
        }
    }
    for(int i =0;i<n;i++)
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    
    return dist;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    int x, y, z;
    for(int i =0;i<m;i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    int src; 
    cin >> src;

    vector<int> dist = dijsktra(adj, n, src);

    for(int i : dist)
        cout << i << " ";
    
    cout << "\n";

    return 0;
}