#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hashArr(n+1);

        for(int i =0; i<n;i++)
        {
            hashArr[nums[i]]++;
        }
    

    for(int i =0; i<=n;i++)
    {
        if(hashArr[i] == 0)
        {
            return i;
        }
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

    cout << missingNumber(a);

    
}