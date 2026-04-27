#include<bits/stdc++.h>

using namespace std;

class SegmentTree{
private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    void push(int v, int tl, int tr)
    {
        if(lazy[v] != 0)
        {
            int tm = (tl + tr)/2;

            tree[2*v] += lazy[v] * (tm-tl+1);
            tree[2*v+1] += lazy[v] * (tr-tm);

            lazy[2*v] += lazy[v];
            lazy[2*v + 1] += lazy[v];

            lazy[v] = 0;
        }
    }
};

int main()
{


    return 0;
}