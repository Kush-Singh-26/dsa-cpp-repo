#include<bits/stdc++.h>
using namespace std;

bool helper(vector<vector<char>>& board, string& word, int row, int col, int idx, int m, int n)
{
    if(idx == word.length())
        return true;
    
    if(row < 0 || col < 0 || row == m || col == n || board[row][col] != word[idx] || board[row][col] == '#')
        return false;
    
    char c = board[row][col];

    board[row][col] = '#';

    bool top = helper(board, word, row-1, col, idx+1, m,n);
    bool right = helper(board, word, row, col+1, idx+1, m, n);
    bool left = helper(board, word, row, col-1, idx+1, m, n);
    bool down = helper(board, word, row+1, col, idx+1, m, n);

    board[row][col] = c;

    return top || right || left || down;
}

bool exist(vector<vector<char>>& board, string word) 
{
    int m = board.size();
    int n = board[0].size();

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(board[i][j] == word[0])
            {
                if(helper(board, word, i, j, 0, m, n))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    int r,c;
    cin >> r >> c;

    vector<vector<char>> board(r, vector<char>(c));
    for(int i = 0;i<r;i++)
        for(int j= 0;j<c;j++)
            cin >> board[i][j];
    
    string word; cin >> word;

    cout << exist(board, word) << "\n";


    return 0;
}


/*
1. first find the first char of the word in the board.
2. backtrack top, bottom, right, left & right of the selected word.
3. use a special char like '#' to mark the cell as visited which is later reverted back to undo.
*/