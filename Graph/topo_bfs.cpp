// Kahn's Algorithm
#include<bits/stdc++.h>

using namespace std;


vector<int> topo(vector<int> adj[], int V)
{
    vector<int> ans;

    vector<int> Indegree(V, 0);
    for(int i=0;i<V;i++)
    {
        for(auto it : adj[i])
        {
            Indegree[it]++;
        }
    }

    queue<int> q;

    for(int i=0;i<V;i++)
        if(Indegree[i] == 0)
            q.push(i);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto it : adj[node])
        {
            Indegree[it]--;

            if(Indegree[it] == 0)
                q.push(it);
        }
    }

    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i =0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> ans = topo(adj, n);

    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}