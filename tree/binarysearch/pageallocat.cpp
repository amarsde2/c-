#include<bits/stdc++.h>
using namespace std;



bool isFessiable(int arr[], int n, int m, int mid){
    int requiredStudent = 1;int sum = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > mid){
            return false;
        }
        if(sum + arr[i] > mid){
           requiredStudent++;
           sum = arr[i];
           if(requiredStudent > m){
             return false;
           }
        } else{
            sum += arr[i];
        }
    } 
    return true;
}

int allocateMinimumPage(int arr[], int n, int m){
    int sum = 0;
    for(int i = 0; i < n; i++){
       sum += arr[i];
    }
    int ans = INT_MAX;
    int low = 0; int high = sum;

    while(low <= high){
        int mid = (low + high)/2;

        if(isFessiable(arr, n, m, mid)){
            high = mid-1;
            ans  = min(ans, mid);
        } else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    int arr[] = {12,34,67,90};
    int n  = 4;
    int m = 2;

    cout << allocateMinimumPage(arr, n ,m) << endl;

    return 0;
}