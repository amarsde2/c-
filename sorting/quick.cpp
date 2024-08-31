#include<bits/stdc++.h>
using namespace std;



int partion(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;
    int j = low;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high){

    if(low < high){
       int mid = partion(arr, low, high);
       quicksort(arr, low, mid-1);
       quicksort(arr, mid+1, high);
    } else{
        return ;
    }
}


int main(){
    int arr[] = {11, 8, 13, 4, 5, 6, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}