#include<bits/stdc++.h>

using namespace std;

int f(vector<int>& a, int i, vector<int>& dp)
{
    if(i == 0)
        return a[0];
    if(i == 1)
        return max(a[0], a[1]);

    if(dp[i] != -1)
        return dp[i];
    
    return dp[i] = max(a[i] + f(a, i-2, dp), f(a, i-1, dp));
}

int helper(vector<int>& a)
{
    int n = a.size();
    vector<int> dp(n, -1);
    return f(a, n-1, dp);
}

int main()
{
    int n; cin >> n; 
    vector<int> a(n);
    for(int i = 0;i<n;i++)
        cin >> a[i];
    cout << helper(a);
    return 0;
}