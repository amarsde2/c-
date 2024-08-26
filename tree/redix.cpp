#include<bits/stdc++.h>
using namespace std;


void sortItem(int arr[], int n, int pos){
    int max = (arr[0] / pos) % 10;   
    for(int i = 1; i < n; i++){
        if((arr[i]/pos) % 10 > max){
            max = (arr[i] / pos) % 10;
        }
    }


    int count[max+1];
    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }

    for(int i = 0 ; i < n; i++){
      ++count[(arr[i]/pos)%10];
    }

    for(int i = 1 ; i <= max; i++){
        count[i] = count[i] + count[i-1];
    }
    
    int out[n];

    for(int j = n-1; j >= 0; j--){
       out[--count[(arr[j]/pos)%10]] = arr[j];
    }

    for(int i = 0; i < n; i++){
        arr[i] = out [i];
    }

}

void redisSort(int arr[], int n){
    int max = arr[0];

    for(int i = 1; i < n; i++){
       if(arr[i] > max){
          max = arr[i];
       }
    }

    for(int pos = 1; max/pos > 0; pos *= 10){
        sortItem(arr, n, pos);
    }
}

int main(){
    int arr[] = {11,323,235,77,23,2212};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0; i<n; i++){
        cout << arr[i] <<  " " ;
    }

    cout << endl;

    redisSort(arr,n);
    cout << "Numbers after sorting: \n";

      
    for(int i=0; i<n; i++){
        cout << arr[i] <<  " " ;
    }


    return 0;
}