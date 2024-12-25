//BS approach

#include<iostream>

using namespace std;

int BS(int arr[], int n) {
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    
    while(start<end) {
        if(arr[mid] < arr[0] )
            end = mid;
        else
            start = mid+1;
        mid = start + (end - start) / 2;
    }
    return start;
}

int main() {
    int arr[5] = {7, 9, 2, 3, 6}, n=5;
    int res = BS(arr, n);
    cout << res;
    return 0;
}