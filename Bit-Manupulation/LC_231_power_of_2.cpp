#include<bits/stdc++.h>
using namespace std;


bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        return n&(n-1) ? 0 : 1;
    }

// n&(n-1) => removes last (rightmost) set bit
// power of 2 will have only one set bit

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
    if(isPowerOfTwo(n)) cout << "true\n" ;
    else cout << "false\n";
}