// #include"/Users/anuragupperwal/stdc++.h"
#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    int sumA=0, sumB=0;
    cin>>a>>b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    for(int i=0; i<a.length(); ++i){
        sumA += a[i];
        sumB += b[i];
    }
    if(sumA == sumB) cout<<"0\n";
    else if(sumA >= sumB) cout<<"1\n";
    else cout<<"-1\n";

    return 0;
}