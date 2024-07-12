#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, max1 =0;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                count++;
                max1 = max(max1,count);
            }

            else
                count =0;
        }
        return max1;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << findMaxConsecutiveOnes(a);

    
}