#include<iostream>
#include <ctype.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    char c = s[0];
    s[0] = toupper(s[0]);
    cout<<s;

    return 0;
}