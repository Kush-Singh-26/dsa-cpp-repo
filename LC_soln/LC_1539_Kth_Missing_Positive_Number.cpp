#include<bits/stdc++.h>
using namespace std;

    int findKthPositive(vector<int>& arr, int k) {
        int c =0, j=0;
        int h = arr.back();
        for(int i =1;i<h;i++)
        {
            if(i != arr[j])
            {
                c++;
                if(c == k) return i;
            }

            else
            {
                j++;
            }
        }

        int n = arr.size();

        return arr[n-1] + (k-c);
    }


    int findKthPositiveBinary(vector<int>& arr, int k) {
        int n = arr.size();

        int l = 0, h = n-1;

        while(l<=h)
        {
            int mid = (l+h)/2;
            int missing_no = arr[mid] - mid - 1;

            if(missing_no < k) l = mid+1;
            else h = mid-1;
        }

        return k+h+1;
    }
int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;
    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << findKthPositiveBinary(a,k);

    return 0;
}