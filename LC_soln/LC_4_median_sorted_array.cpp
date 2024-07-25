#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        for(int i=0;i<nums1.size();i++)
            merge.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            merge.push_back(nums2[i]);
        sort(merge.begin(),merge.end());
        int n = merge.size();
        if(n%2 == 0)
        {
            double temp (merge[n/2] + merge[n/2-1]);
            return temp/2;
        }
        else
            return merge[n/2];
    }
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0;i<n;i++)
        cin >> a[i];
    
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i =0;i<m;i++)
        cin >> b[i];
    
    double ans = findMedianSortedArrays(a,b);
    cout << ans;
    return 0;
}