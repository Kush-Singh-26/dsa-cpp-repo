#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n,0);
    vector<int> col(m,0);

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i] || col[j])
                matrix[i][j] = 0;
        }
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
        

    setZeroes(a);

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