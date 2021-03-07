// Minimum number of jumps to reach end

#include<iostream>

using namespace std;

int main() {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}, size, gap, increment=0, jumps=0;  //{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
    size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<size;) {
        gap = (size-1)-i;
        // jumps++;
        for(int j=arr[i]+i; j>i; --j) {
            if(arr[j] <= gap)   {
                increment = arr[j];
                // cout<<i<<" "<<arr[j]<<"\n";
                jumps++;
                break;
            }
            else {
                j=gap;
            }
        }
        if(increment!=0) i += increment;
        else ++i;
        increment=0;
    }

    cout<<"Total jumps: "<<jumps;

    return 0;
}