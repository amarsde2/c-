#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[], int n){
    int max = arr[0];

    for(int i = 1; i < n; i++){
       if(arr[i]  > max){
           max = arr[i];
       }
    }

    int count[max+1];

    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        ++count[arr[i]];
    }
   
    for(int i = 1; i <= max; i++){
        count[i] = count[i] + count[i-1];
    }

    int ans[n];
    for(int j = n -1; j >= 0; j--){
        ans[--count[arr[j]]] = arr[j];
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " " ;
    }
}

int main(){
    int arr[] = {1,2,5,6,73,2,3,8,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    countsort(arr,n);

    return 0;
}