#include<bits/stdc++.h>
using namespace std;

int funcEntered = 0;

int helper(int n, vector<int>& dp)
{
    funcEntered++;
    if(n<=1)
        return n;
    if(dp[n] != -1)
        return dp[n]; 

    return dp[n] = helper(n-1, dp) + helper(n-2, dp);
}

int fib(int n)
{
    vector<int> dp(n+1, -1);
    return helper(n, dp);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << "\n" << funcEntered << "\n";
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int funcEntered = 0;

int helper(int n)
{
    funcEntered++;
    if(n<=1)
        return n;

    return helper(n-1) + helper(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout << helper(n) << "\n" << funcEntered << "\n";

    return 0;
}
*/