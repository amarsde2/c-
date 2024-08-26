#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int low, int high){
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}


int leftPartion(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
         swap(arr, i, j);
         i++;
        }
    }

    swap(arr, i, high);

    return i;
}


int partionRight(int arr[], int low, int high){
    srand(time(NULL));
    int r = low + rand()%(high-low);
    swap(arr, r, high);

    return leftPartion(arr, low, high);
}

void quicksort(int arr[], int low,int high){
    
    if(high-low <= 0){
        return;
    } else{
       int r = partionRight(arr, low, high);
       quicksort(arr, low, r-1);
       quicksort(arr, r+1, high);
    }

}

int main(){
    int arr[] = {6, 4, 12, 8, 15, 16};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
}