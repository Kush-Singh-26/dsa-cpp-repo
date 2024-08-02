#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0,h= n-1,mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[l] <= nums[mid])
            {
                if(nums[l] <= target && target <= nums[mid])
                    h = mid-1;
                else 
                    l = mid+1;
            }

            else
            {
                if(nums[mid] <= target && target <= nums[h])
                    l = mid+1;
                else
                    h = mid-1;
            }
        }

        return -1;
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

    cout << search(a,target);

    return 0;
}