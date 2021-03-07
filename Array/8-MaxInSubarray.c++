//to find the continuous subarray's maximum sum
//Kadane's algorithm
//Algorithmic Paradigm: Dynamic Programming
#include<iostream>

using namespace std;

int main() {
    int maxSoFar=0, maxEndingHere=0, arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}, size;
    size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<size; ++i) {
        maxEndingHere += arr[i];
        if(maxEndingHere < 0)  maxEndingHere = 0;
        else if(maxSoFar < maxEndingHere)    maxSoFar = maxEndingHere;
    }

    cout<<"Maximum value in subarray: "<<maxSoFar;
    return 0;
}
