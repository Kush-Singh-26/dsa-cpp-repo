#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int n = nums.size();
        int mid =0 , low = 0, high = n-1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++; low++;
            }

            else if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }

            else mid++;
        }
    }

    int main()
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sortColors(a);

        for(int i =0; i<n;i++)
            cout << a[i] << " ";
        return 0;
    }