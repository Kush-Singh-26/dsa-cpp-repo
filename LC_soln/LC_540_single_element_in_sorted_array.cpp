#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, h =n-2,mid;
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return(nums[0]);
        if(nums[n-1] != nums[n-2]) return (nums[n-1]);
        while(l<=h)
        {
            mid = (l+h)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) return nums[mid];
            if((mid % 2 == 0) && (nums[mid] == nums[mid-1]) || (mid % 2 == 1) && (nums[mid] == nums[mid+1]))
                h= mid-1;
            else
                l = mid+1;
        }
        return -1;
    }

int main()
{
    int n;
    cin >> n;

    
    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << singleNonDuplicate(a);

    return 0;
}