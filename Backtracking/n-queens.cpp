#include<bits/stdc++.h>
using namespace std;

void helper(int n, int col, vector<vector<string>>& ans, vector<string>& ds, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal)
{
    if(col == n)
    {
        ans.push_back(ds);
        return;
    }

    for(int row = 0; row<n; row++)
    {
        if(leftRow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0 && lowerDiagonal[row + col] == 0)
        {
            ds[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n-1+col-row] = 1;
            helper(n, col+1, ans, ds, leftRow, upperDiagonal, lowerDiagonal);
            ds[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n-1+col-row] = 0;
        }
    }
}

vector<vector<string>> N_Queens(int n)
{
    vector<vector<string>> ans;
    vector<int> leftRow(n,0);
    vector<int> upperdiag(2*n -1,0);
    vector<int> lowerdiag(2*n - 1,0);
    vector<string> ds(n);
    string s(n, '.');
    for(int i =0;i<n;i++)
        ds[i] = s;
    helper(n, 0, ans, ds, leftRow, upperdiag, lowerdiag);
    return ans;
}   


int main()
{
    int n; cin >> n;
    vector<vector<string>> ans = N_Queens(n);

    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j<ans[0].size();j++)
            cout << ans[i][j] << "\n";
        cout << "------------\n";
    }

    return 0;
}