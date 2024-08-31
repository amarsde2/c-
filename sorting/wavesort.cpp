#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    // wave sort
    int i = 1;
    while( i < n){
        if(arr[i] > arr[i-1]){
            swap(arr[i],arr[i-1]);
        }

        if(arr[i] > arr[i+1] && i <= n-2){
            swap(arr[i+1],arr[i]);
        }

        i += 2;
    }

    for(int i = 0; i < n; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
}