#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        int t = 0;
        int b = m-1;
        int l = 0;
        int r = n-1;

        vector<int>ans;

        while(t<=b && l<=r)
        {
            for(int k =l; k<=r;k++)
                ans.push_back(a[t][k]);
            t++;

            for(int k =t; k<=b;k++)
                ans.push_back(a[k][r]);
            r--;

            if(t<=b)
            {
                for(int k =r; k>=l;k--)
                    ans.push_back(a[b][k]);
                b--;
            }

            if(l<=r)
            {
                for(int k =b; k>=t;k--)
                    ans.push_back(a[k][l]);
                l++;
            }
        }

        return ans;
    }
int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;
    vector <vector<int>> a(n,vector<int>(m));

    for(int i=0; i<n;i++) 
        for(int j =0; j<m;j++)
            cin >> a[i][j];
        


    vector<int> ans = spiralOrder(a);

    for(int i=0; i<ans.size();i++) 
    {
        cout << ans[i]<< " ";        
    }
    
    return 0;
}