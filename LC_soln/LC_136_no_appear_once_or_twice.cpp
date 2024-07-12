#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++)
            mpp[nums[i]]++;
        
        for(auto it:mpp)
        {
            if(it.second == 1)
                return it.first;
        }

        return -1;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << singleNumber(a);

    
}