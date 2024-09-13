#include<bits/stdc++.h>
using namespace std;


bool isPerfect(int n){
    int sum = 1;

    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            if(n/i == i){
                sum += i;
            } else{
                sum += i + n/i;
            }
        }
    }  
    
    if(sum == n && n != 1){
        return true;
    }

    return false;
}

int maxSum(int arr[], int n , int k){
    int sum = 0;
    for(int i=0; i<k; i++){
        sum += arr[i];
    }

    int ans = sum;

    for(int i = k ; i < n ; i++){
        sum = sum + arr[i] - arr[i-k];
        ans = max(ans, sum);
    }

    return ans;
}

int maxSumPrefectNumber(int arr[], int n, int k){

    for(int i = 0; i < n; i++){
        if(isPerfect(arr[i])){
            arr[i] = 1;
        } else{
            arr[i] = 0;
        }
    }

    return maxSum(arr, n, k);
}

int main(){
    int arr[] = {28,2,3,6,496,99,8128,24};
    int n = 8;
    int k = 4;
    cout << maxSumPrefectNumber(arr, n,k) << endl;
}