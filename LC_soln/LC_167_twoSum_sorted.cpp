#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left =0;
        int right = n-1;
        while(left<right)
        {
            int sum = nums[left] + nums[right];

            if(sum == target)
            {
                return {left,right};
            }

            if(sum < target) left++;
            else right --;
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