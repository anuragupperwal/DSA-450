#include<iostream>

using namespace std;

void merge(int arr[], int start, int mid, int end) {
   int tempArr[50], i = start, j = mid+1, k=start;

   while(i<=mid && arr[i]<0) {
      tempArr[k] = arr[i];
      i++;
      k++;
   } 
   while(j<=end && arr[j]<0) {
      tempArr[k] = arr[j];
      k++;
      j++;
   }
   while(i<=mid && arr[i]>0) {
      tempArr[k] = arr[i];
      i++;
      k++;
   }
   while(j<=end && arr[j]>0) {
      tempArr[k] = arr[j];
      k++;
      j++;
   }

   for(k=start; k<=end; ++k) arr[k] = tempArr[k];

}

void negativeOnSideLeft(int arr[], int start, int end) {
   if(start<end){
      int mid = (start+end)/2;

      negativeOnSideLeft(arr, start, mid);
      negativeOnSideLeft(arr, mid+1, end);

      merge(arr, start, mid, end);
   }
}

int main() {
   int arr[] = {-6,2,-7,3,-4,-8,3,1}, size=8; 
   // size = sizeof(arr)/sizeof(arr[0]);
   negativeOnSideLeft(arr, 0, size-1);
   
   for(int i=0; i<size; ++i) cout<<arr[i]<<" ";
   return 0;
}