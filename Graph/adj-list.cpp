#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // vector<vector<int>> a(n+1, vector<int>(n+1, 0));

    // int x, y;
    // for (int i = 0; i < m; i++)   
    // {
    //     cin >> x >> y;
    //     a[x][y] = 1;
    //     a[y][x] = 1;   
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << a[i][j] << " ";
    //     cout << "\n";
    // }

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

    return 0;
}
