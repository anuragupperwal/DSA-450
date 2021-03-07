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

void arrayUnioun(int arr1[], int arr2[], int size1, int size2) {
    int temp[size1+size2], uniounArr[size1+size2], count=0, i, j=0;

    //copying both the sets to temp array
    for(i=0; i<size1; ++i) temp[i] = arr1[i];
    for(i=size1; i<size1+size2; ++i) {
        temp[i] = arr2[j];
        j++;
    }
    
    //sorting temp array
    mergeSort(temp, 0, size1+size2-1);

    //removing duplicate elements 
    j=0;
    for(int i=0; i<size1+size2; ++i) {
        if(temp[i]!=temp[i+1]) {
            uniounArr[j] = temp[i];
            j++;
        }
        if(i==size1+size2) uniounArr[j] = temp[i+1];
    } 
    
    //final unioun of both the sets
    for(int i=0; i<j; i++) cout<<uniounArr[i]<<" ";

}

void arrayIntersection(int arr1[], int arr2[], int size1, int size2) {
    int k=0, intersectionArr[size1+size2];

    for(int i=0; i<size1; ++i) {
        for(int j=0; j<size2; ++j) {
            if(arr1[i]==arr2[j]) {
                intersectionArr[k] = arr1[i];
                ++k;
                break;
            }
        }
    }
    for(int i=0; i<k; i++) cout<<intersectionArr[i]<<" ";
}

int main() {
    int arr1[] = {1, 3, 4, 5, 7}, arr2[] = {2, 3, 5, 6, 3, 7}, size1, size2;
    size1 = sizeof(arr1)/sizeof(arr1[0]);
    size2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Intersection: ";
    arrayIntersection(arr1, arr2, size1, size2);
    cout<<"\nUnioun: ";
    arrayUnioun(arr1, arr2, size1, size2);
    return 0;
}