#include <iostream>

using namespace std;

int rotation(int arr[], int n)
{
    // no. of times an array is rotated equals to the index of minimum element
    int l = 0, r = n-1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        int prev = (mid + (n-1))%n;
        int next = (mid + 1)%n;

        if(arr[prev] > arr[mid] && arr[next] > arr[mid])
            return mid;

        if(arr[l] > arr[mid])
            r = mid-1;

        else
            l = mid+1;
    }
    return -1;
}


int main()
{
    int arr[] = {13, 15, 19, 25, 28, 29, 1, 7, 8, 12};
    int n = sizeof(arr)/sizeof(int);

    cout << rotation(arr, n) << endl;

}