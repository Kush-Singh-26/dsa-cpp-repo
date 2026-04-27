#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int l, int r, string s)
{
    while(l<r)
    {
        if(s[l] != s[r])
            return false;
        l++; 
        r--;
    }
    return true;
}

void helper(int idx, int n, string& s, vector<string>& ds, vector<vector<string>>& ans)
{
    if(idx == n)
    {
        ans.push_back(ds);
        return;
    }

    for(int i = idx; i < n;i++)
    {
        if(isPalindrome(idx, i, s))
        {
            ds.push_back(s.substr(idx, i-idx+1));
            helper(i+1, n, s, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    helper(0, s.size(), s, ds, ans);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<vector<string>> a = partition(s);
    for(auto x : a)
    {
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
            
}