#include<bits/stdc++.h>
using namespace std;


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

int convert2decimal(string x)
{
    int len = x.size();
    int num =0, p2 =1;
    for(int i = len-1; i>=0;i--)
    {
        if(x[i] == '1')
        {
            num += p2;
        }
        p2 *= 2;
    }
    return num;
}

int main()
{
    int n; cin >> n;
    string x; cin >> x;
    cout << convert2binary(n) << "\n" << convert2decimal(x);
    return 0;
}