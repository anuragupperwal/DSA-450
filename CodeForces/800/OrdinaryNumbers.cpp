#include<iostream>

using namespace std;

int digitCountFun(int n) {
    int count=0;
    while(n!=0) {
        count++;
        n = n/10;
    }
    return count;
}

int main() {
    int t;
    cin>>t;

    for(int i=0; i<t; ++i) {
        int n, num1, num2, temp, digitCount;
        bool flag = true;
        cout<<endl;
        cin>>n;
        temp = n;
        
        digitCount = digitCountFun(n);

        if(digitCount == 1) {
            cout<<"YES";
        }
        else {
            for(int j=0; j<digitCount-1; ++j) {
                num1 = temp%10;
                temp /=10;
                num2 = temp%10;
                if(flag == true && num1 == num2) {
                    flag = true;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                cout<<"YES";
            }
            else {
                cout<<"NO";
            }
        }  
        
    }
    return 0;
}