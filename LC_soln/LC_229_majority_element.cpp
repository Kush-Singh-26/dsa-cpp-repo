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

vector<int> majorityElement_optimal(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int ele1 = INT_MIN, ele2 = INT_MIN, count1 =0, count2 =0;

        for(int i =0;i<n;i++)
        {
            if(count1 == 0 && nums[i] != ele2)
            {
                ele1 = nums[i];
                count1++;
            }
            
            else if(count2 == 0 && nums[i] != ele1)
            {
                ele2 = nums[i];
                count2++;
            }

            else if(nums[i] == ele1) count1++;

            else if(nums[i] == ele2) count2++;

            else 
                {
                    count1--; count2--;
                }
        }

        count1 =0; count2 =0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == ele1) count1++;
            if(nums[i] == ele2) count2++;
        }

        int limit = n/3;
        if(count1 > limit) ans.push_back(ele1);
        if(count2 > limit) ans.push_back(ele2);
 
       
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