#include <bits/stdc++.h>
using namespace std;

void rotate_brute(vector<int>& nums, int k) {
        
        //brute force
        int n = nums.size();
        vector<int> temp(k);
        k = k%n;
        for(int i = n-k; i<n;i++)
        {
            temp[i+k-n] = nums[i];
        }

        for(int i =n-k-1; i>=0; i--)
        {
            nums[i+k] = nums[i];
        }

        for(int i =0; i<k;i++)
        {
            nums[i] = temp[i];
        }
    }
void reverseArr(vector<int>& nums, int start, int end)
    {
         while(start<=end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

void rotate_optimal(vector<int>& nums, int k) {

    
        
        //brute force
        int n = nums.size();
        vector<int> temp(k);
        k = k%n;
        int start = 0;
        int end = k;

        reverseArr(nums,0,n-k-1);

        for(int i =0; i<n;i++)
        cout << nums[i] << " ";

        cout <<"\n";
        reverseArr(nums,n-k,n-1);

        for(int i =0; i<n;i++)
        cout << nums[i] << " ";

        cout <<"\n";
        reverseArr(nums,0,n-1);
        
    }


int main()
{
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n;i++) 
        cin >> a[i];

    int k;
    cin >> k;

    rotate_optimal(a,k);
    for(int i =0; i<n;i++)
        cout << a[i] << " ";
    
}