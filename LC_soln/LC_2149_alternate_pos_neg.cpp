#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        vector<int> arrp;
        vector<int> arrn;
        for(int i =0;i<n;i++)
        {
            if(nums[i] <0) arrn.push_back(nums[i]);
            else arrp.push_back(nums[i]);
        }

        for(int i = 0;i<n/2;i++)
        {
            nums[2*i] = arrp[i];
            nums[(2*i) + 1] = arrn[i];
        }

        return nums;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    rearrangeArray(a);

    for(int i=0;i<n;i++)
    cout << a[i] << " ";
    return 0;
}