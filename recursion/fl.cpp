#include<bits/stdc++.h>
using namespace std;

int firstO(int arr[], int n , int start, int index){
    
    if(start == n) return -1;

    if(arr[start] == index){
        return start;
    }
     
    return firstO(arr, n , start+1, index);
    
} 

int lastO(int arr[], int n ,int end, int index){
  
    if(end < 0) return -1;

    if(arr[end] == index){
        return end;
    } 
    return lastO(arr, n , end-1, index);
    
}


int main(){
    int arr[]  = {1,2,3,4,5,2,7};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout << firstO(arr, n, 0, 3) << endl;
    cout << lastO(arr, n, n-1, 3) << endl;
    return 0;
}