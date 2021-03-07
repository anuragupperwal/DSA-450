#include<iostream>

using namespace std;

void shiftingFun(int arr[], int start, int end) {
    while(start<end) {

        if(arr[start] < 0 && arr[end] > 0 ) {
            start++;
            end--;
        }
        else if(arr[start] > 0 && arr[end] <0 ) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        else if(arr[start] < 0 ) start++;
        else if(arr[end] > 0) end--;

    }
    
}

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6}, arrLen;
    arrLen = sizeof(arr)/sizeof(arr[0]);

    shiftingFun(arr, 0, arrLen);

    for(int i=0; i<arrLen; ++i) cout<<arr[i]<<" ";

    return 0;
}