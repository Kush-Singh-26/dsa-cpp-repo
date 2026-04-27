#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int f(int n, vector<int>& dp)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];

    dp[n] = 0;
    for (int i = 1; i <= 6; i++) {
        dp[n] = (dp[n] + f(n - i, dp)) % MOD;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
    return 0;
}