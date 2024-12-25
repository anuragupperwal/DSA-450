#include<iostream>

using namespace std;

int main() {
    int n, count=0;
    cin>>n;
    while(n--) {
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 1) {
            if(b==1) count++;
            else if(c==1) count++;
        }
        else if(b==1) {
            if(c==1) count++;
        }
    }
    cout<<count<<"\n";

    return 0;
}