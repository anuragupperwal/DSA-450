#include<iostream>
#include<vector>

using namespace std;

int isPossible(int arr[], int n, int m, int *ans, int arrSum, int mid) {
    int sum = 0, totalSum = 0, count = 1;

    if(sum>mid) {
        totalSum = sum - arr[i];
        count++;
        i--
    }
}

int allocation(int arr[], int n, int m) {
    int s = 0, e=0;
    for (int i = 0; i < n; ++i)
        e += arr[i];
    int mid = s + (e - s) / 2;
    int x, *ans, arrSum=e;
    *ans = -1;

    while(s<e) {
        x = isPossible(arr, n, m, &ans, arrSum, mid);
        if(x==1) {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans; 
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout<<allocation(arr, n, m);

    return 0;
}