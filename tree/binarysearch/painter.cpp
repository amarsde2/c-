#include<bits/stdc++.h>
using namespace std;

int findPainter(int arr[], int n , int mid){
    int sum = 0;
    int painter = 1;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > mid){
            sum = arr[i];
            painter++;
        }
    }
    return painter;
}

int minimumTimeToPaint(int arr[], int n, int m){
    int low, high;
    int k = 0, totaltime = 0;
    for(int i = 0; i < n; i++){
       totaltime += arr[i];
       k = max(k, arr[i]);
    }
    low = k;
    high = totaltime;
    while(low < high){
        int mid = (low + high) / 2;
        int painter = findPainter(arr, n, mid);
        if(painter <= m){
            high = mid;
        } else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;

    cout << minimumTimeToPaint(arr, n, m) << endl;

    return 0;
}
