#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n){

    int maxSum = 0;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
 

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


    int maxSum = 0;
    int nowrapsnum = kadane(arr, n);
    int wrapsum = 0;
    int totalsum = 0;

    for(int i=0;i < n ; i++){
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    
    wrapsum = totalsum + kadane(arr, n);

    maxSum = max(wrapsum, nowrapsnum);
 
    cout << maxSum << endl;

    return 0;
}