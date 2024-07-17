#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = INT_MAX; 
        int profit =0;
 
        for(int i =0;i<n;i++)
        {
            mini = min(prices[i], mini);

            profit = max(profit,prices[i] - mini);

        }

        return profit;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << maxProfit(a);

    return 0;
}