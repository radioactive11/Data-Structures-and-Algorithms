#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <algorithm>
#include <string>


using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <char> vc;
typedef pair <int, int> pii;
typedef pair <int, char> pic;


//int COUNTER = 0;

int merge(int arr1[], int low, int mid, int high)
{
    static int COUNTER = 0;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2];

    for(int i=0; i<n1; i++)
    {
        left[i] = arr1[low + i];
    }
    for(int j=0; j<n2; j++)
    {
        right[j] = arr1[mid + 1 + j];
    }

    int i=0, j=0, k=low;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr1[k] = left[i];
            i++;
        }
        else
        {
            arr1[k] = right[j];
            j++;
            COUNTER += sizeof(left)/sizeof(left[0]);
        }
        k++;
    }
    while(i < n1)
    {
        arr1[k] = left[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr1[k] = right[j];
        j++;
        k++;
    }
    return COUNTER;
}


int mergeSort(int arr1[], int low, int high)
{
    int counter = 0;
    if(low < high)
    {
        int mid = low + (high - low)/2;

        mergeSort(arr1, low, mid);
        mergeSort(arr1, mid+1, high);

        counter = merge(arr1, low, mid, high);

    }
    return counter;
}


int main()
{
    int n;
    cin >> n;
    int arr1[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr1[i];
    }

    mergeSort(arr1, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr1[i] << " ";

    return 0;
}