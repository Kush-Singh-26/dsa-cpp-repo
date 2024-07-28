#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m-1 , b = n-1;
        for(int i =m+n-1;i>=0;i--)
        {
            if(b<0) break;

            if(a >= 0 && nums1[a] > nums2[b])
            {
                nums1[i] = nums1[a];
                a--;
            }

            else
            {
                nums1[i] = nums2[b];
                b--;
            }
        }
    }

int main()
{
    int m;
    cin >> m;

    int n;
    cin >> n;
    vector <int> a(m+n);
    vector <int> b(n);
    for(int i=0; i<m;i++) 
        cin >> a[i];
    for(int i =m;i<m+n;i++)
        a[i] = 0;
    for(int i =0;i<n;i++)
        cin >> b[i];
    merge(a,m,b,n);
    for(int i =0; i<m+n;i++)
        cout << a[i] << " ";
    
}