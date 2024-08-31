#include<bits/stdc++.h>
using namespace std;


bool isSortedArray(int arr[], int n){
   
    if(n == 1) return true;
    
    if(arr[0] < arr[1] && isSortedArray(arr+1, n-1)){
        return true;
    } else{
        return false;
    }

}



int main(){
    int arr[] = {1,2,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(isSortedArray(arr,n)){
        cout << "Array is sorted" << endl;
    } else{
        cout << "Array is not sorted" << endl;
    }

    return 0;
}