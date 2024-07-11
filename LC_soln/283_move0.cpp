#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j =1; j<n ; j++)
        {
            if(nums[j] != 0 && nums[i] == 0)
            {
                swap(nums[i],nums[j]);
                for(int k=0; k<n;k++)
                    cout << nums[k] << " ";
                cout << "\n"; 
                i++;
            }
        }
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    moveZeroes(a);
    for(int i =0; i<n;i++)
        cout << a[i] << " ";
    
}