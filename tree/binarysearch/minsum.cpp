#include<bits/stdc++.h>
using namespace std;



int findMaximumSum(int arr[], int n, int x){
    int sum = 0;
    int start =  0;
    int end = 0;
    int minln = n+1;
 
    while(end < n){
      while(sum <= x && end < n){
        sum += arr[end++];
      }  
      while(sum > x && start < n){
        if(end - start < minln){
          minln = end-start;
        }
        sum -= arr[start++];
      }
    }
    return minln;
}


int main(){
    int arr[] = {1,4,45,6,10,19};
    int n = 6;
    int x = 51;
   
    cout << findMaximumSum(arr, n, x) << endl;
}