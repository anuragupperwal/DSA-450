#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector <string> v;
    for(int i=0; i<n; ++i) {
        string s;
        cin>>s;
        v.push_back(s);
    }


    for(int i=0; i<n; ++i) {
        if(v[i].length() <11) cout<<v[i]<<"\n";
        else {
            int len = v[i].length();
            string res, word;
            word = v[i][0];
            len -= 2;
            word += to_string(len);
            word +=v[i].back();
            cout<<word<<"\n";
        }
    }

    return 0;
}