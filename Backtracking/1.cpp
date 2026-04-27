#include<bits/stdc++.h>

using namespace std;

void builder(string curr, vector<char>& letters, vector<bool>& used)
{
    if(curr.length() == 2)
    {
        cout << curr << "\n";
        return;
    }

    for(size_t i =0 ; i< letters.size();i++)
    {
        if(!used[i])
        {
            used[i]=true;
            builder(curr + letters[i], letters,used);
            used[i]=false;
        }
    }
}


int main()
{
    vector<char> letters = {'a', 'b', 'c'};
    vector<bool> used(letters.size(), false);
    builder("", letters, used);
    
    return 0;
}