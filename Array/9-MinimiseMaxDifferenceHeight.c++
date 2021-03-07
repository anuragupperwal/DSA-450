//Minimize the maximum difference between the heights

#include<iostream>

using namespace std;

void sortArray(int arr[], int size) {
    int k, j;
    for(int i=1; i<size; ++i){
        k = arr[i];
        for(j=i-1; j>=0 && arr[j]>k; --j) 
            arr[j+1] = arr[j];
        arr[j+1]=k;
    }
}

int minimiseMaxDifferenceHeight(int arr[], int size, int key) {
    int small, large, ans, sub, add;

    ans = arr[size-1] - arr[0];
    small = arr[0] + key;
    if(arr[size-1]-key < 0) large = arr[size-1] + key;
    else large = arr[size-1] - key;

    if(small>large) large += 2*key; //agar large small se kam h to mai instead of sub, add kr rha hu. But gfg pe vo swap kr rha h jo ki mai pehle kr rha tha aur usse testcase fail kr rha tha.

    // for(int i=1; i<size-1; ++i) {
    //     sub = arr[i] - key;
    //     add = arr[i] + key;

    //     if(large - sub <= add - small) small = sub;
    //     else large = add;
    // } 
    // return min(ans, large-small);
    
    for(int i=1; i<size-1; i++) {
        sub = arr[i] - key;
        add = arr[i] + key;
        if(add<large) continue;
        else if (sub>small) continue;
        else {
            if((large - sub) < (add - small)) small = sub;
            else large = add;
        }
    }

    return large-small;
}

int main() {
    int arr[] = {1, 2, 3}, size, key, minimumDiff;
    size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter key: ";
    cin>>key;

    sortArray(arr, size);
    minimumDiff = minimiseMaxDifferenceHeight(arr, size, key);
    cout<<"Maximum difference is: "<<minimumDiff<<" \n";
    for(int i=0; i<size; ++i) cout<<arr[i]<<" ";
    return 0;
}