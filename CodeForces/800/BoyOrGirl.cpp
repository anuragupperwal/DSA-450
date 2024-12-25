#include<iostream>
#include<map>

using namespace std;

int main() {
    string s;
    cin>>s;
    map<char, int> m;
    for(int i=0; i<s.length(); ++i) {
        m[s[i]] = 1;
    }

    if(m.size() %2 != 0) cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";

    return 0;
}