#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> temp(k);
        k = k%n;
        for(int i = n-k; i<n;i++)
        {
            temp[i+k-n] = nums[i];
        }

        for(int i =n-k-1; i>=0; i--)
        {
            nums[i+k] = nums[i];
        }

        for(int i =0; i<k;i++)
        {
            nums[i] = temp[i];
        }
    }


int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    int k;
    cin >> k;

    rotate(a,k);
    for(int i =0; i<n;i++)
        cout << a[i] << " ";
    
}