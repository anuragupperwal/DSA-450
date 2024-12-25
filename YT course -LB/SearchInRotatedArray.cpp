#include<iostream>

using namespace std;

int BS(int arr[], int k, int start, int end) {
    int mid = start + (end - start) / 2;

    // for (int i = start; i < end; ++i)
    //     cout << " " << arr[i] << " ";
    while (start < end)
    {
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            end = mid;
        else
            start = mid + 1;
        mid = start + (end - start) / 2;
        }
    return -1;
}

int SearchInRotatedArray(int arr[], int n, int k) {
    int start = 0, end = n , pivot, res=0;
    int mid = start + (end - start) / 2;

    while(start<end) {
        if(arr[mid] > arr[0])
            start = mid + 1;
        else
            end = mid;
        mid = start + (end - start) / 2;
    }
    pivot = start;
    if (k == arr[0])
        return 0;
    else if (k > arr[0])
        res = BS(arr, k, 0, pivot);
    else res = BS(arr, k, pivot, n);

        return res;
}

int main() {
    int arr[] = {1,3}, k;
    cin >> k;
    cout << "Required value is at index: " << SearchInRotatedArray(arr, 6, k);

    return 0;
}