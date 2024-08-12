#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>& bloomDay, int day, int m, int k)
    {
        int n = bloomDay.size();
        int count=0, boq=0;
        for(int i =0;i<n;i++)
        {
            if(bloomDay[i] <= day)
            {
                count++;
            }
            else
            {
                boq += count/k;
                count = 0;
            }
        }

        boq += count/k;

        return(boq >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long c = (long long)m*k;
        if (n < c) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }

        int l =mini;
        int h = maxi;
        int mid;
        while(l<=h)
        {
             mid = l + (h - l) / 2;
            if(possible(bloomDay, mid, m ,k))
                h = mid-1;
            else 
            l = mid+1;

        }
        return l;
    }

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    int k;
    cin >> k;
    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << minDays(a,m,k);

    return 0;
}