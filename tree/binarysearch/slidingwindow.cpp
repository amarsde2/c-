#include<bits/stdc++.h>
using namespace std;



int findMaximumSum(int arr[], int k, int n, int x){
    int sum = 0;
    int pointer =  0;
    int ans;
    for(int i = 0 ; i < k ; i++){
        sum += arr[i];
    }
    ans = sum;
    for(int i = k ; i < n ; i++){
       sum = sum - arr[pointer++] + arr[i];
       if(sum < x){
        ans = max(ans, sum);
       }
    }
    return ans;
}

int main(){
    int arr[] = {7,5,4,6,8,9};
    int k = 3;
    int n = 6;
    int x = 20;
   
    cout << findMaximumSum(arr, k, n, x) << endl;
}