#include<iostream>

using namespace std;

int main() {
    int arr[] = {2, 0, 1, 2, 0, 1, 0, 1}, size, i=0, j=0, zero=0, one=0, two=0;
    size = sizeof(arr)/sizeof(arr[0]);
    for(; i<size; ++i) {
        switch(arr[i]) {
            case 0: zero++;
                break;
            case 1: one++;
                break;
            case 2: two++;
                break;
        }
    }
    for(i=0; i<zero; ++i) arr[i] = 0;
    for(i=zero; i<one+zero; ++i) arr[i] = 1;
    for(i=zero+one; i<zero+one+two; ++i) arr[i] = 2;

    for(i =0; i<size; ++i) cout<<arr[i]<<" ";
    return 0;
}