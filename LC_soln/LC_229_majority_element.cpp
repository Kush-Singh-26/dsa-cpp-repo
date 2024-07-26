#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n/3;
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i =0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        for(auto it :mp)
        {
            if(it.second > limit)
                ans.push_back(it.first);
        }

        return ans;
    }
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0;i<n;i++)
        cin >> a[i];
    
    
    vector ans = majorityElement(a);
    for(int i =0;i<ans.size();i++)
        cout <<  ans[i] << " ";
    return 0;
}