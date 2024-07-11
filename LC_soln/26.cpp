#include<bits/stdc++.h>
using namespace std;

    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i =1;i<nums.size();i++)
        {
            if(nums[j] != nums[i])
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0; i<n;i++) 
        cin >> a[i];

    removeDuplicates(a);

    for(int i =0; i<n;i++)
        cout << a[i] << " ";
    
}

