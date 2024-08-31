#include<bits/stdc++.h>
using namespace std;


long long merge(int arr[], int low, int mid, int high){
    long long inversion  = 0;
    int l1,l2,i;
    int ans[7];
    int n1 = mid - low + 1;
    for(l1 = low, l2 = mid+1, i = low; l1 <=mid && l2 <= high; i++){
        if(arr[l1] <= arr[l2]){
          ans[i] = arr[l1++];
        } else{
          ans[i] = arr[l2++];
          inversion += n1 - l1;
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

    return inversion;
}


long long mergeSort(int arr[], int low, int high){
    long long inverse = 0;
    if(low < high){
        int mid = (low + high)/2;
        inverse +=  mergeSort(arr,low, mid);
        inverse += mergeSort(arr, mid+1, high);
        inverse += merge(arr,low, mid, high);
    } 
    return inverse;
}

int main(){
   
    int arr[] = {3,5,6,9,1,2,7,8} ;
    int n = 8;
    long long inversion = 0;
   
    
    inversion = mergeSort(arr, 0, n-1);

    for(int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << inversion << endl;

    return 0;
}