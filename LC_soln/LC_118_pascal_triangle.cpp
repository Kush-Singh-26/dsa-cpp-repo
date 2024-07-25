#include<bits/stdc++.h>
using namespace std;

vector<int> row(int n)
    {
        vector<int> rowvec;
        int ele =1;
        rowvec.push_back(1);
        for(int i=1;i<n;i++)
        {
            ele = (ele * (n-i) / i);
            rowvec.push_back(ele);
        }

        return rowvec;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i =1;i<=numRows;i++)
        {
            vector <int> currow = row(i);
            ans.push_back(currow);
        }

        return ans;
    }


int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans = generate(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}