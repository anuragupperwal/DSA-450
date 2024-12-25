#include<iostream>
// #include"/Users/anuragupperwal/stdc++.h"
#include<bits/stdc++.h>

using namespace std;

int main() {
    // int t;
    // cin>>t;
    // while(t--){
    long long int n, k, count=0;
    // cout<<"\n";
    cin>>n>>k;

    if( k > (n+1)/2) {
        cout<<(k - ((n+1)/2))*2; 
    }
    else {
        cout<<k*2-1;   
    }

    // }
    return 0;
}
//1 2 3 4 5 6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 
//1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33  2  4  6  8 10 12 14 16 18 20 22 24 26 28 30 32 34