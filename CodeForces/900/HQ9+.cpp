#include<iostream>
#include<map>

using namespace std;

void print_map(map<char, int> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

int main() {
    string s;
    cin>>s;
    map <char, int> m;

    for(int i=0; i<s.length(); ++i) {
        m[s[i]] =1;
    }

    if(m['H']== 1 || m['Q'] == 1 || m['9'] == 1 ) cout<<"YES";
    else cout<<"NO";

    // print_map(m);

    return 0;
}