#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for(char x : s)
    {
        if(!st.empty() && (st.top() == '(' &&  x == ')' || st.top() == '[' &&  x == ']' || st.top() == '{' &&  x == '}'))
        {
            st.pop();
        }
        else
        {
            st.push(x);
        }
    }
    return st.empty();
}


int main()
{
    string str;
    cin >> str;
    if(isValid(str))
        cout << "true";
    else
        cout << "false";
    return 0;
}