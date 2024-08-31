#include<bits/stdc++.h>
using namespace std;


void merge(int *ans,int *arr, int low, int mid, int high){
    int l1,l2,i;
    for(l1 = low, l2 = mid+1, i = low; l1 <=mid && l2 <= high; i++){
        if(arr[l1] <= arr[l2]){
          ans[i] = arr[l1++];
        } else{
          ans[i] = arr[l2++];
        }
    }

    while(l1 <= mid){
        ans[i++] = arr[l1++];
    }

    while(l2 <= high){
        ans[i++] = arr[l2++];
    }

    for(i = low; i <= high; i++){
        arr[i] = ans[i];
    }
}


void mergeSort(int *arr, int low, int high, int *ans){

    if(low < high){
        int mid = (low + high)/2;
        mergeSort(arr,low, mid-1, ans);
        mergeSort(arr, mid+1, high, ans);
        merge(ans, arr,low, mid, high);
    } else{
        return;
    }
}

int main(){
   
    int arr[] = {12,33,21,25,64};
    int n = 5;
    int ans[4];
    
    mergeSort(arr, 0, n, ans);

    for(int i = 0; i < n;i++){
        cout << arr[i] << endl;
    }

    return 0;
}