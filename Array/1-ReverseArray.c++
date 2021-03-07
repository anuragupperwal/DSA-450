#include<iostream>

using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j]=temp;
}

int main() {
    int arr[] = {3,4,8,2,6,7,5}, size, i, j;
    size = sizeof(arr)/sizeof(arr[0]);

    for(i=0, j=size-1; i<j; ++i, --j) {
        swap(arr, i, j);
    }

    for( i=0; i<size; ++i) cout<<arr[i]<<" ";

    return 0;
}