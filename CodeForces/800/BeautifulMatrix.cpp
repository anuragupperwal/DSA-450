#include<iostream>
#include<map>

using namespace std;

int main() {
    int i=1, j=1, pi, pj, res = 0;
    map <int, map <int, int> > matrix;
    for(i=1; i<=5; ++i) {
        for(j=1; j<=5; ++j) {
            int a;
            cin>>a;
            matrix[i][j] = a;
            if(a == 1) {pi = i; pj = j;}
        }
    }

    res += abs(3-pi);
    res += abs(3-pj);
    cout<<res<<"\n";


    

    return 0;
}