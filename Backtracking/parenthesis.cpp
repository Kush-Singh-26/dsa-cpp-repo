#include<bits/stdc++.h>
using namespace std;

void build(int openCount, int closeCount, string current, int n, vector<string>& arr)
{
    if(openCount == n && closeCount == n)
    {
        arr.push_back(current);
        return;
    }

    if(openCount<n)
        build(openCount+1, closeCount, current + '(',n,arr);

    if(closeCount<openCount)
        build(openCount, closeCount+1, current + ')',n,arr);
}

int main()
{
    vector<string>ans;
    int n;
    cin >> n;
    build(0,0,"",n,ans);

    for(auto x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}