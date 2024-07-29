#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0,h =n-1;
        while(l<=h)
        {
            int m = (l+h)/2;
            if(nums[m] == target) return m;
            else if(nums[m] > target) h = m-1;
            else  l = m+1;
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