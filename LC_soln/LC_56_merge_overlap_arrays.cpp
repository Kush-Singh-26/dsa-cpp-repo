#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            if(ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }

        return ans;
    }


int main() {
    int n,m;
    cin >> n;
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            cin >> a[i][j];

    vector<vector<int>> ans = merge(a);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}