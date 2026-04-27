#include<bits/stdc++.h>
#include <vector>
using namespace std;

class SegmentTree{
    private:
        vector<int> tree;
        int n;

        void build(const vector<int>&a, int v, int tl, int tr)
        {
            if(tr == tl)
                tree[v] = a[tr];
            else
            {
                int tm = (tl+tr)/2;
                build(a, 2*v, tl, tm);
                build(a, 2*v +1, tm+1, tr);
                tree[v] = tree[2*v] + tree[2*v + 1];
            }
        }

        void update(int v, int tl, int tr, int pos, int new_val)
        {
            if(tl == tr)
                tree[v] = new_val;
            else
            {
                int tm = (tl + tr)/2;
                if(pos <= tm)
                    update(2*v, tl, tm, pos, new_val);
                else
                    update(2*v +1, tm+1, tr, pos, new_val);
            }
            tree[v] = tree[2*v] + tree[2*v +1];
        }

        int query(int v, int tl, int tr, int l, int r)
        {
            if(l>r)
                return 0;
            if(l == tl && r == tr)
                return tree[v];

            int tm = (tl+tr)/2;
            return query(2*v, tl, tm, l, min(r, tm)) + query(2*v +1, tm+1, tr, max(l, tm+1),r);
        }

public:

    SegmentTree(const vector<int>&a)
    {
        n = a.size();
        tree.resize(4*n);
        build(a, 1, 0, n-1);
    }
    
    void update(int pos, int new_val)
    {
        update(1, 0, n-1, pos, new_val);
    }
    
    int query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

};

int main()
{
    vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree st(data);
    
    cout << "Sum of range [1,3]" << st.query(1, 3) << "\n";
    st.update(1, 10);
    cout << "Updated sum of range [1,3]" << st.query(1, 3) << "\n";


    return 0;
}
