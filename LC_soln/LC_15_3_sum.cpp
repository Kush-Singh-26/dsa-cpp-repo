#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i =0;i<n;i++)
        {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;

            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum <0) j++;
                else if(sum>0) k--;
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                  
                }
            }
        }

    return ans;
    }


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0;i<n;i++)
        cin >> a[i];

    vector<vector<int>> ans = threeSum(a);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}