#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int>& vis,vector<int> adj[], stack<int>& st)
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it])
            dfs(it, vis, adj, st);
    }

    st.push(node);
}

vector<int> topo(vector<int> adj[], int V)
{
    vector<int> vis(V, 0);
    stack<int> st;

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            dfs(i, vis, adj, st);
    }

    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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