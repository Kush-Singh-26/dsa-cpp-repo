#include<bits/stdc++.h>
using namespace std;

int nodays(vector<int>& weights, int cap)
    {
        int days = 1;
        int load = 0;
        int n = weights.size();

        for(int i=0;i<n;i++)
        {
            if(load + weights[i] > cap)
            {
                days++;
                load = weights[i];
            }
            else
                load += weights[i];
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
    int l = *max_element(weights.begin(), weights.end());
    int h = accumulate(weights.begin(), weights.end(), 0);   
    int mid;
    while(l <= h)
    {
        mid = (l+h)/2;
        if(nodays(weights, mid) <= days)
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

    int days;
    cin >> days;
    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << shipWithinDays(a,days);

    return 0;
}