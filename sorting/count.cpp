#include<bits/stdc++.h>
using namespace std;


void countSort(int arr[], int n){
    int max = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i] > max){
            max =arr[i];
        }
    }

    int count[max+1] = {0};

    for(int i = 0 ; i < n ; i++){
        count[arr[i]]++;
    }
    
    for(int i = 1; i <= max; i++){
        count[i] = count[i] + count[i-1];
    }

    int output[n];
    for(int i = n-1; i >= 0 ; i--){
        output[--count[arr[i]]] = arr[i];
    }

    for(int i = 0 ; i < n ; i++){
       arr[i] = output[i];
    }
}


int main(){
    int arr[] = {2,3,7,7,9,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    countSort(arr,n);

    for(int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    
    return 0;
}