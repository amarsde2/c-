#include<bits/stdc++.h>
using namespace std;

struct result{
    int min;
    int max;
};

struct result maxMin(int arr[] , int low, int high){
      result rest, left, right;
      if(low == high){
        rest.min = arr[low];
        rest.max = arr[low];
        return rest;
      } else if(high == low + 1){
        if(arr[low] > arr[high]){
            rest.min = arr[high];
            rest.max = arr[low];
        } else{
            rest.min = arr[low];
            rest.max = arr[high];
        }
        return rest;
      }

      int mid = (low + high) / 2;

      left = maxMin(arr, low, mid );
      right = maxMin(arr, mid+1, high);

      rest.min = left.min > right.min ? right.min : left.min;
      rest.max = left.max > right.max ? left.max : right.max;

      return rest;

}


int main(){
    struct result rest;
    int arr[] = {1,24,22,11,23,56,78,2,3,0};
    rest = maxMin(arr, 0, 9);
    cout << rest.max << rest.min << endl;
    return 0;

}