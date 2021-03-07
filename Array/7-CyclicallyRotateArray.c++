#include<iostream>

using namespace std;

int main() {
    int arr[]= {1, 2, 3, 4, 5, 6, 7, 8}, size, temp;
    size = sizeof(arr)/sizeof(arr[0]);

    temp = arr[size-1];
    for(int i=size-1; i>0; --i) arr[i] = arr[i-1];
    arr[0] = temp;
    cout<<"cyclically rotated array: ";
    for(int j=0; j<size; ++j) cout<<arr[j]<<" ";

}