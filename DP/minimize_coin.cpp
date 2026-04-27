#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;

int helper(vector<int>& dp, vector<int>& c, int x)
{
    if(x == 0) return 0;
    if(x < 0) return INF;

    if(dp[x] != -1) return dp[x];

    int ans = INT_MAX;
    for(int i : c)
        ans = min(ans, helper(dp, c,x - i) + 1);
    
    return dp[x] = ans; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;   
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0;i<n;i++)
        cin >> c[i];
    vector<int> dp(x+1, -1);
    int result = helper(dp, c, x);

    cout << (result >= INF ? -1 : result) << "\n";
    return 0;
}