#include<bits/stdc++.h>
using namespace std;


bool isFesiable(int arr[], int mid, int k, int n){
    int pos = arr[0];
    int element = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] - pos >=  mid){
           pos = arr[i];
           element++;
           if(element  == k){
            return true;
           }
        }
    }
    return false;
}

int getMaximunOfMinimun(int arr[],  int n, int k){
    sort(arr, arr+n);
    int low = 1;
    int result = -1;
    int high = arr[n-1];

    while(low < high){
        int mid = (low + high)/2;
        if(isFesiable(arr, mid, k, n)){
            result = max(result, mid);
            low = mid+1;
        } else{
            high = mid;
        }
    }
    return result;
}

int main(){
    int arr[] = {1,2,8,4,9};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << getMaximunOfMinimun(arr,n,k) << endl;

    return 0;
}