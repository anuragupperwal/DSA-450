#include<iostream>

using namespace std;

void merge(int arr[], int start, int mid, int end){ 
    int i = start;
    int j = mid+1;
    int k = start, temp[100];
    while(i<=mid && j<=end) {
        if(arr[i]<arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }

    if(i>mid) {
        while(j<=end) {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }

    if(j>end) {
        while(i<=mid) {
            temp[k]=arr[i];
            i++;
            k++;
        }
    }

    for(int i=start; i<=end; ++i) arr[i] = temp[i];
}

void mergeSort(int arr[], int start, int end){
    if(start<end) {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[]= {7,2,8,3,4,9,1}, size, toFindAtIndex;
    size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Enter index: ";
    cin>>toFindAtIndex;
    //to sort the array
    mergeSort(arr, 0, size-1);

    //to find kth max, min array
    cout<<"Value at "<<toFindAtIndex<<" is: "<<arr[toFindAtIndex];


    return 0;
}
