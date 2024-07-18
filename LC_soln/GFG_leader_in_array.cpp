#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(int n, vector<int> & arr) {
        // Code here
        vector<int> ans;
        
        int max = arr[n-1];
        ans.push_back(arr[n-1]);
        
        for(int i =n-2;i>=0;i--)
        {
            if(arr[i]>=max)
            {
                max = arr[i];
                ans.push_back(arr[i]);
            }
        }
        
        reverse (ans.begin(),ans.end());
        
        return ans;
    }

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    vector<int> ans = leaders(n,a);

    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";
    return 0;
}