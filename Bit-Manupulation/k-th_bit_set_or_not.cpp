#include<bits/stdc++.h>
using namespace std;


bool checkKthBit(int n, int k) {
        int bit = n>>k;
        return bit&1;
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
    int n,i; cin >> n >> i;
    cout << convert2binary(n) << "\n";
    if(checkKthBit(n,i)) cout << "true\n" ;
    else cout << "false\n";
}