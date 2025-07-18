#include<bits/stdc++.h>
using namespace std;


int setBit(int n) {
        return n | (n+1);
    }

string convert2binary(int n)
{
    if(n == 0) return "0";
    string res = " ";
    while(n > 0)
    {
        if(n%2 == 1) res += '1';
        else res += '0';
        n = n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int n; cin >> n;
    cout << convert2binary(n) << "\n";
    int res = setBit(n);
    cout << res << "\n" << convert2binary(res);
}