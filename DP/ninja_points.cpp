/*
#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid, int day, int last, vector<vector<int>>& dp)
{
    if(dp[day][last] != -1)
        return dp[day][last];
    
    if(day == 0)
    {
        int maxi = 0;
        for(int i = 0;i<=2;i++)
            if(i != last)
                maxi = max(maxi, grid[0][i]);
        return dp[day][last] = maxi;
    }

    int maxi = 0;

    for(int i = 0;i<=2; i++)
    {
        if(i != last)
        {
            int act = grid[day][i] + helper(grid, day-1, i, dp);
            maxi = max(maxi, act);
        }
    }

    return dp[day][last] = maxi;
}

int solve(vector<vector<int>>& grid, int n)
{
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return helper(grid, n-1, 3, dp);
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(3));
    for(int i =0;i<n;i++)
        for(int j = 0;j<=2;j++)
            cin >> grid[i][j];
    
    cout << solve(grid, n);

    return 0;
}

*/

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(3));
    for(int i =0;i<n;i++)
        for(int j = 0;j<=2;j++)
            cin >> grid[i][j];
    
    vector<vector<int>> dp(n, vector<int>(4));
    dp[0][0] = max(grid[0][1], grid[0][2]);
    dp[0][1] = max(grid[0][0], grid[0][2]);
    dp[0][2] = max(grid[0][0], grid[0][0]);
    dp[0][3] = max(grid[0][0], max(grid[0][1], grid[0][2]));

    for(int day = 1;day<n;day++)
    {
        for(int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            
            for(int task = 0; task<=2;task++)
            {
                if(task != last)
                {
                    int act = grid[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], act);
                }
            }
        }
    }

    cout << dp[n-1][3];

    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(3));
    for(int i =0;i<n;i++)
        for(int j = 0;j<=2;j++)
            cin >> grid[i][j];

    vector<int> prev(4, 0);
    prev[0] = max(grid[0][1], grid[0][2]);
    prev[1] = max(grid[0][0], grid[0][2]);
    prev[2] = max(grid[0][0], grid[0][0]);
    prev[3] = max(grid[0][0], max(grid[0][1], grid[0][2]));

    for(int day = 1;day<n;day++)
    {
        vector<int> temp(4,0);
        for(int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            
            for(int task = 0; task<=2;task++)
            {
                if(task != last)
                {
                    temp[last] = max(temp[last], grid[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    cout << prev[3];

    return 0;
}