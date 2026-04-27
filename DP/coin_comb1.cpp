#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int n, x;
vector<int> coins;
vector<int> dp;

int helper(int sum)
{
    if(sum == 0)
        return 1;
    if(sum <0)
        return 0;
    if(dp[sum] != -1) return dp[sum];

    long long total = 0;
    for(int c : coins)
    {
        if(sum - c >= 0)
        {
            total += helper(sum-c);
            if(total >= MOD)
                total -= MOD;
        }
    }
    return dp[sum] = (int)(total%MOD);
}

int main()
{
    cin >> n >> x;
    coins.resize(n);
    for(int i = 0;i<n;i++)
        cin >> coins[i];
    
    dp.assign(x+1, -1);
    cout << helper(x) << "\n";
    return 0;
}