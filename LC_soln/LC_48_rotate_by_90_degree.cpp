#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i =0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
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
        

    rotate(a);

    for(int i=0; i<n;i++) 
    {
        for(int j =0; j<m;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}