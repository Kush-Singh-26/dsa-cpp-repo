#include<bits/stdc++.h>
using namespace std;

int missingNumberBrute(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<=n;i++)
        {
            int flag = 0;
            for(int j =0; j<n ;j++){
                if(nums[j] == i)
                {
                    flag =1;
                    break;
                }
            }

            if(flag == 0) return i;

        }
        return -1;
    }


int missingNumberBetter(vector<int>& nums) {
        int n = nums.size();
        vector<int> hashArr(n+1);

        for(int i =0; i<n;i++)
        {
            hashArr[nums[i]]++;
        }
    

    for(int i =0; i<=n;i++)
    {
        if(hashArr[i] == 0)
        {
            return i;
        }
    }

    return -1;
}


int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum1 = (n*(n+1))/2;
        int sum2=0;
        for(int i =0; i<n;i++)
        {
           sum2 += nums[i];
        }  

        return sum1-sum2;    
}

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    cout << missingNumber(a);

    
}