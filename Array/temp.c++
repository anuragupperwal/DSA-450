#include<iostream>

using namespace std;


void merge(int uniounArr[], int start, int  mid, int end) {
    int i=start, j=mid+1, k=start, tempArr[100];
    while(i<=mid && j<=end) {
        if(uniounArr[i] < uniounArr[j]) {
            tempArr[k] = uniounArr[i];
            k++;
            i++;
        }
        else {
            tempArr[k] = uniounArr[j];
            k++;
            j++;
        }
    }
    while(i<=mid) {
        tempArr[k] = uniounArr[i];
        k++;
        i++;
    }
    while(j<=end) {
        tempArr[k] = uniounArr[j];
        j++;
        k++;
    }

    for(int i=start; i<=end; ++i) uniounArr[i] = tempArr[i];

}

void mergeSort(int uniounArr[], int start, int end) {
    if(start<end) {
        int mid = (start+end)/2;

        mergeSort(uniounArr, start, mid);
        mergeSort(uniounArr, mid+1, end);

        merge(uniounArr, start, mid, end);
    }
}


int main() {
    int arr[] =  {1, 3, 4, 5, 7, 2, 3, 5, 6, 3, 7 }, arrLen=11;
    mergeSort(arr, 0, arrLen-1);

    for(int i=0; i<arrLen; ++i) cout<<arr[i]<<" ";

    return 0;
}