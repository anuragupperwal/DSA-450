#include<iostream>
#include<map>

using namespace std;

int main() {
    int n, x=0;
    cin>>n;
    for(int i=0; i<n; ++i) {
        int count=0;
        map <int, int> m;
        string s;
        cin>>s;
        m['-'] = 0;
        m['+'] = 0;
        m['X'] = 0;

        m[s[0]] +=1;
        m[s[1]] +=1;
        m[s[2]] +=1;

        if(m['+'] != 0 )x++;
        else if(m['-'] != 0) x--;
    }
    cout<<x<<"\n";
    
    return 0;
}