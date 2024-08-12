#include<bits/stdc++.h>
using namespace std;

double hours(vector<int>& piles, int speed)
    {
        double totalhours = 0;
        int n = piles.size();
        for(int i = 0; i<n;i++)
        {
            totalhours += (piles[i] + speed -1)/speed;
            
        }

        return totalhours;
    }

    int maxi(vector<int>& piles)
    {
        int m = INT_MIN;
        int n = piles.size();
        for(int i = 0;i<n;i++)
        {
            m = max(m,piles[i]);
        }

        return m;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = maxi(piles);

        int low =1;
        while(low<=high)
        {
            int mid = (high+low)/2;
            double totalH = hours(piles,mid);

            if(totalH <= h)
                high = mid-1;
            else
                low = mid+1; 
        }      
        return low;
    }

int main()
{
    int n;
    cin >> n;

    int hours;
    cin >> hours;
    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << minEatingSpeed(a,hours);

    return 0;
}