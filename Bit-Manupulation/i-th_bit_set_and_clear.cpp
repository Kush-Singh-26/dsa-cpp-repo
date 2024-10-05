#include<bits/stdc++.h>
using namespace std;


void bitManipulation(int n, int i) {
        int bit = n >> (i-1);
        int res = bit & 1;
        cout << res << " " << (int) (n | (1<<i-1)) << " " << (int) (n & ~(1 << i-1));
    }

int main()
{
    int n,i; cin >> n >> i;
    bitManipulation(n,i);
}