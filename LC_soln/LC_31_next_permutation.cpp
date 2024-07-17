#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int breakp = -1;
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                breakp = i;
                break;
            }
        }

        if(breakp == -1)
        return reverse(nums.begin(), nums.end());

        for(int i =n-1; i>breakp;i--)
        {
            if(nums[i] > nums[breakp])
            {
                swap(nums[i], nums[breakp]);
                break;
            }
        }

        reverse(nums.begin()+breakp+1,nums.end());
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    nextPermutation(a);

    for(int i=0;i<n;i++)
    cout << a[i] << " ";
    return 0;
}