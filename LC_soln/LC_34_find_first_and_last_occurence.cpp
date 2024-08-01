#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        int n = nums.size();
        int l =0, h= n-1;
        int mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(nums[mid] == target)
            {
                start = mid;
                h = mid-1;

            } 
            else if(nums[mid] > target) h = mid-1;
            else l = mid+1;
        }

        l =0, h = n-1;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(nums[mid] == target)
            {
                end = mid;
                l = mid+1;

            } 
            else if(nums[mid] > target) h = mid-1;
            else l = mid+1;
        }

        return {start,end};
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

    vector<int> ans(2);
    ans = searchRange(a,target);

    for(int i=0; i<2;i++) 
        cout << ans[i] << " ";
    return 0;
}