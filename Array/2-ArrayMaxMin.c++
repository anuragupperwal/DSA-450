#include<iostream>

using namespace std;

int main() {
    int arr[] = {2,7,4,3,6,8,5}, size, max, min;
    size = sizeof(arr)/sizeof(arr[0]);
    min=arr[0];
    max=arr[0];

    for(int i=1; i<size; ++i) {
        if(arr[i]<min) min=arr[i];
        if(arr[i]>max) max=arr[i];
    }

    cout<<"Max: "<<max<<"\nMin: "<<min;
    return 0;
}