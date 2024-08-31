#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {3,5,6,9,1,2,7,8};
    int n = 8;
    int totalinversion = 0;

    for(int i = 0 ; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j] && i < j){
                totalinversion++;
            }
        }
    }


    cout << totalinversion << endl;
    cout << endl;
}