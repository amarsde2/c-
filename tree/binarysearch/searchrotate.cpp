#include<bits/stdc++.h>
using namespace std;

int findIndexOfKey(int arr[], int key, int low, int high){
     
    if(low > high){
        return -1;
    }
  
    
    int mid = (low + high) / 2;
    if(arr[mid] == key) return mid;
        
    if(arr[low] <= arr[mid] && key >= arr[low] && key <= arr[mid]){
        return findIndexOfKey(arr, key, low, mid-1);
    }

    if(key >= arr[mid] && key  <= arr[high]){
        return findIndexOfKey(arr, key, mid +1, high);
    }

   return findIndexOfKey(arr, key, low, mid-1);
    
}

int main(){
    int arr[] = {6,7,8,9,10,1,2,5};
    int n = 8;
    int key = 8;
    cout << findIndexOfKey(arr, key, 0, n-1) << endl;

    return 0;
}
