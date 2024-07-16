#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum= 0;
        int maxi =INT_MIN;
        for(int i =0;i <n;i++)
        {
            sum += nums[i];
            
            maxi = max(sum,maxi);
            if(sum < 0 ) sum =0;
        }

        return maxi;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << maxSubArray(a);

    return 0;
}