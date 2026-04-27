/*
#include<bits/stdc++.h>

using namespace std;

int helper(vector<vector<int>>& grid, int n, int m, int i, int j)
{
    if(i >= n || j >= m)
        return INT_MAX;
    if(i == n-1 && j == m-1)
        return grid[i][j];
    
    int down = helper(grid, n, m, i+1, j);
    int right = helper(grid, n, m, i, j+1);

    return grid[i][j] + min(down, right);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0;i<n;i++) 
        for(int j = 0;j<m;j++)
            cin >> grid[i][j];

    cout << helper(grid, n, m, 0, 0); 
    
    return 0;
}
*/


#include<bits/stdc++.h>

using namespace std;
 


int helper(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>>& dp)
{
    if(i >= n || j >= m)
        return INT_MAX;
    if(i == n-1 && j == m-1)
        return grid[i][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int down = helper(grid, n, m, i+1, j, dp);
    int right = helper(grid, n, m, i, j+1, dp);

    return dp[i][j] = grid[i][j] + min(down, right);
}

int dp_grid(int n, int m, vector<vector<int>>& grid)
{
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return helper(grid, n, m, 0, 0, dp);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0;i<n;i++) 
        for(int j = 0;j<m;j++)
            cin >> grid[i][j];

    cout << dp_grid(n, m, grid); 
    
    return 0;
}