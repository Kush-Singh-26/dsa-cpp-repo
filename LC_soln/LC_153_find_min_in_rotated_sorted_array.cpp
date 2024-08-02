#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        int s = INT_MAX;
        int n = nums.size();
        int l =0, h = n-1, mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(nums[l] <= nums[mid])
            {
                s = min(s,nums[l]);
                l = mid+1;
            }
            else  
            { 
                s = min(s,nums[mid]);
                h  = mid-1;
            }
        }
        return s;
    }

int main()
{
    int n;
    cin >> n;

    int target;
    cin >> target;
    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << findMin(a);

    return 0;
}