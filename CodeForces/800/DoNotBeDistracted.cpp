#include<iostream>

using namespace std;

int main() {
    int t, n;
    string taskString;

    cin>>t;
    for(int i=0; i<t; ++i) {
        cin>>n>>taskString;
        int tasks[n], idx=0;
        bool flag=false;

        
        for(int i=0; i<n-1; ++i) {
            if(task[i] == task[i+1]) {
                continue;
            }  && taskString[idx] == task[i]) {
                flag = true;
            }
        }

    }
    



    return 0;
}