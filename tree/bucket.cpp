#include<bits/stdc++.h>
using namespace std;

void bucketSotr(int arr[], int n){
    int max = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int b[max+1],i;

    for(int i = 0; i <= max; i++){
        b[i] = 0;
    }

    for(int i = 0 ; i < n; i++){
        b[arr[i]]++;
    }

    for(int i = 0, j=0;  i < max+1; i++){
        while(b[i] > 0){
           arr[j++] = i;
           b[i]--;
        }
    }
    
}


int main(){
    int arr[] = {11,20,10,18,29,39,30,20,49};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    bucketSotr(arr,n);
    cout << endl;
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}