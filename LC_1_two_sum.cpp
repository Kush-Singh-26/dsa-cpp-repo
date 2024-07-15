#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map <int,int> mp;
    int n =nums.size();
    for(int i =0;i<n;i++)
    {
        int num = nums[i];
        int rem = target - num;
        if(mp.find(rem) != mp.end())
        {
            return {i, mp[rem]};
        }

        mp[num] = i;
    }   
    return {-1,-1};
    }

int main()
{
    int target;
    cin >> target;
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    vector <int> ans = twoSum(a,target);
    for(int i =0; i<ans.size();i++)
    {
        cout<<ans[i] << " ";
    }



    
}