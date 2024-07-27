#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, k = n - 1;
                while (l < k) {
                    long long sum = nums[i] ;
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum < target)
                        l++;
                    else if (sum > target)
                        k--;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        l++;
                        k--;
                        while (l < k && nums[l] == nums[l - 1])
                            l++;
                        while (l < k && nums[k] == nums[k + 1])
                            k--;
                    }
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

    int target;
    cin >> target;
    vector<vector<int>> ans = fourSum(a, target);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}