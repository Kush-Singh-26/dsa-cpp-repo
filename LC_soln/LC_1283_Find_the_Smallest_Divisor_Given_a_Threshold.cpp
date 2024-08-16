#include<bits/stdc++.h>
using namespace std;

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        int low = 1, high = maxi, mid;
        while (low <= high) {
            mid = (low + high) / 2;

            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += ceil((double)(nums[j]) / (double)(mid));
            }
            if (sum <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout <<smallestDivisor(a,m);

    return 0;
}