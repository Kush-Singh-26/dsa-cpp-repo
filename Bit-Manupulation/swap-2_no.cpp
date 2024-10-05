#include<bits/stdc++.h>
using namespace std;


pair<int, int> get(int a, int b){
        a = a^b;
        b = a^b;
        a = a^b;
        return pair<int,int>{a,b};
    }

int main()
{
    int a,b; cin >> a >> b;
    pair<int,int> ans = get(a,b); 
    cout << ans.first << " " << ans.second << "\n";
}