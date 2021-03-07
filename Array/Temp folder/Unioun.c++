#include<iostream>
#include<map>
// #include<pair>

using namespace std;

int UniounUsingMap(int arr[], map<int, int> &result, int size, int i) {
    int value = 1;
    if(i < size) {
        result.insert(pair<int, int>(arr[i],  value));
        i++;
        return UniounUsingMap(arr, result, size, i);
    }    
    return 0;
}


// int Union(int *arr, int *result, int size, int i) {
//         int resultArrLen = sizeof(result)/sizeof(*result);

//         // cout<<i<<" "<<resultArrLen<<" Result arr: ";
//         // for(int k=0; k<resultArrLen; ++k) cout<<result[k]<<" ";
        // cout<<"\n";

    // if(i < size ) {
    //     // int resultArrLen = sizeof(result)/sizeof(result[0]);
    //     cout<<"len: "<<resultArrLen<<" \n";
    //     bool check;
    //     if(resultArrLen == 0) {
    //         result[0] = arr[i];
    //         resultArrLen++;

    //     }
    //     else {
    //         for(int j=0; j<resultArrLen; ++j) {
    //             check = false;
    //             if(result[j] == arr[i]) {
    //                 check = true;
    //                 cout<<"here\n"; 

    //                 break;
    //             }
    //         }

    //         if(check != true)  {
    //             result[resultArrLen] = arr[i];
    //             resultArrLen++;
    //         }
    //     }
    //     i++;

    //     cout<<i<<" Result arr: ";
    //     for(int k=0; k<resultArrLen; ++k) cout<<result[k]<<" ";
    //     cout<<"\n";
    //     return Union(arr, result, size, i);
    // }
//     // else return 0;

//     return 0;
// }

int main() {
    map<int, int> result;
    // cin>>m>>n;
    int a[] = {9, 1, 9, 1, 9, 1, 0}, b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int m=sizeof(b)/sizeof(b[0]), n=sizeof(a)/sizeof(a[0]);

    UniounUsingMap(a, result, n, 0);
    UniounUsingMap(b, result, m, 0);
    
    cout<<"Unioun arr: ";
    for(map<int, int>::const_iterator it = result.begin(); it!=result.end(); ++it){
        cout<<it->first<<" ";
    }


    // Union(a, c, n, 0);
    // Union(b, c, m, 0);
    // for(int i=0; i<n; ++i) {
    //     bool check = false;
    //     for(int j=0; j<; ++j) {
    //         if(c[j] == a[i]) {
    //             check = true;
    //             break;
    //         }
    //     }
    //     if(check==false) {
    //         c[idx] = a[i];
    //         idx++;
    //     } 
    // }


    // cout<<idx<<"\n";
    // cout<<"Unioun array: ";
    // for(int j=0; j<m+n; ++j) {
    //     cout<<c[j]<<" ";
    // }

    return 0;
}