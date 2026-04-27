#include <bits/stdc++.h>
using namespace std;

vector<int> DFS(int V, vector<int> adj[])
{
    vector<int> vis(V+1, 0);
    vector<int> dfs;
    stack<int> st;

    for(int start = 1; start<= V; start++)
    {
        if(vis[start])
            continue;
        
        st.push(start);
        vis[start] = 1;

        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            dfs.push_back(node);
            
            for(int i = adj[node].size()-1; i>=0;i--)
            {
                int nbr = adj[node][i];
                if(!vis[nbr])
                {
                    vis[nbr]=1;
                    st.push(nbr);
                }
            }
        }
    }
    return dfs;
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

    vector<int> dfs = DFS(n, adj);
    cout << "DFS\n";
    for(int i= 0;i<dfs.size();i++)
        cout << dfs[i] << " ";
    
    cout << "\n";

    return 0;
}
