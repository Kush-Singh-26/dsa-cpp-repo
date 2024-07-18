#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lastSmaller = INT_MIN;
        int count = 0;
        int longest =1;
        if(n == 0) return 0;

        for(int i = 0;i<n;i++)
        {
            if(nums[i]-1 == lastSmaller)
            {
                count++;
                lastSmaller = nums[i];
            }

            else if(nums[i] != lastSmaller)
            {
                count = 1;
                lastSmaller = nums[i];
            }

            longest = max(longest,count);
        }

        return longest;
    }

int longestConsecutiveOptimal(vector<int>& nums) {
        int n = nums.size();
        int longest =1;
        if(n == 0) return 0;

        unordered_set<int> st;

        for(int i =0;i<n;i++)
            st.insert(nums[i]);

        for(auto it: st)
        {
            if(st.find(it-1) == st.end())
            {
                int count =1;
                int x = it;

                while(st.find(x+1) != st.end())
                {
                    x++;
                    count++;
                }

                longest = max(longest,count);
            }
        }
        return longest;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << longestConsecutiveOptimal(a);

    
    return 0;
}