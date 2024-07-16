#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        int count =0;
        int el;
        int n = nums.size();

        for(int i = 0;i<n;i++)
        {
            if(count ==0)
            {
                el = nums[i];
                count = 1;
            }

            else if (el == nums[i]) count++;
            else count--;
        }

        int cnt =0;
        for(int i =0;i<n;i++)
        {
            if(nums[i] == el)
                cnt++;
        }

        if(cnt > n/2) return el;
        return -1;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << majorityElement(a);

    return 0;
}