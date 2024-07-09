#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)

            if (arr[j] < arr[mini])

                mini = j;

        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int didswap = 0;
        for (int j = 0; j < n - i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didswap = 1;
            }
        }

        if(didswap == 0)
            break;
    }
}

void insertionSort(int arr[], int n)
{
    for(int i =0; i<n; i++)
    {
        int j =i;
        while(j>0 && arr[j] < arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--; 
        }
    }
}

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i =low; i<=high;i++)
        arr[i] = temp[i-low];
}

void mergeSort(int arr[], int low, int high)
{
    if(low >= high) return;

    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);

}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // selectionSort(a, n);
    //bubbleSort(a, n);
    //insertionSort(a,n);
    mergeSort(a, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}