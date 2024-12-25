#include<iostream>
#include<map>

using namespace std;

void print(char c, int plus, map <char, int> m) {
    int rep = m[c];
    for(int i=0; i<rep; ++i) {
        if(m[c] == 0) break;
        cout<<c;
        m[c] -=1;
        if(plus != 0) {
            cout<<'+';
            plus -= 1;
        }
    }
}

int main() {
    string s;
    map <char, int> m;
    
    m['1'] = 0;
    m['2'] = 0;
    m['3'] = 0;
    m['+'] = 0;
    cin>>s;
    for(int i=0; i<s.length(); ++i) {
        m[s[i]] +=1;
    }

    int plus = m['+'];
    
    print('1', plus, m);
    plus -= m['1'];
    print('2', plus, m);
    plus -= m['2'];
    print('3', plus, m);


    return 0;
}