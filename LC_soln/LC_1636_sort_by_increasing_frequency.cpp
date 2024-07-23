#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int,int> mp;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        sort(nums.begin(),nums.end(), [&](int n1, int n2)
        {
            if(mp[n1] != mp[n2])
            {
                return mp[n1] < mp[n2];
            }

            else
                return n2 < n1;
        });

        return nums;
}


int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    vector<int> ans = frequencySort(a);

    for(int i=0; i<n;i++) 
        cout << ans[i] << " ";

    return 0;
}