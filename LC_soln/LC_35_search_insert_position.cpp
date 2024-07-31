#include<bits/stdc++.h>
using namespace std;

//recursive
int binarySearchRecursive(vector<int>& nums, int target, int l,int h)
    {
        if(l>h) return -1;
        int m = (l+h)/2;
        if(nums[m] == target) return m;
        else if(nums[m] > target) return binarySearchRecursive(nums,target, l,m-1);
        else return binarySearchRecursive(nums,target, m+1,h);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearchRecursive(nums,target, 0,n-1);
    }
// iterative
int searchInsert(vector<int>& nums, int target) {
        int l =0, h= nums.size()-1;
        int mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) h = mid-1;
            else l = mid+1;
        }
         return l;
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