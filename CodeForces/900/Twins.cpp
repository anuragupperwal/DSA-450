#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric> 

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    int a, arrSum=0, sum=0, coinCount=0;

    for(int i=0; i<n; ++i) {
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    arrSum = accumulate(arr.begin(), arr.end(), 0);
    
    for(int i=0; i<n; ++i){
        coinCount++;
        sum += arr[i];
        arrSum -= arr[i];
        if(sum > arrSum) {
            break;
        }
    }

    cout<<coinCount;


    return 0;
}