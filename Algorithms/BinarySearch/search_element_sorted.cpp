#include <iostream>
#include <vector>

using namespace std;


int binary_search(int arr[], int n, int key)
{
    int l = 0, r = n-1, mid = -1;
    int ans = -1;
    while(l <= r)
    {
        mid = l + (r-l)/2;

        if(arr[mid] == key)
        {
            ans = mid;
            break;
        }

        else if(arr[mid]<key)
            l = mid+1;
        
        else
            r = mid-1;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    int arr[] = {1, 7, 8, 12, 13, 15, 19, 25, 28, 29};
    int n = sizeof(arr)/sizeof(int);

    cout << binary_search(arr, n, 13) << endl;
    return 0;
}
