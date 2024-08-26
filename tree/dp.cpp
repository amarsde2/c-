#include <bits/stdc++.h>
using namespace std;

int mc[50][50];

int DynamicCost(int *arr, int i , int j){

    if(i == j) {return 0;}

    if(mc[i][j] != -1){
        return 
        mc[i][j];
    }

    mc[i][j]  = INT_MAX;
    
    for(int k = i; k < j ; k++){
        mc[i][j] = min(mc[i][j],DynamicCost(arr, i, k)+ DynamicCost(arr, k+1, j) + arr[i-1] * arr[k] * arr[j]);
    }

    return mc[i][j];
}


int Matrix(int *arr, int n){
    int i = 1, j = n-1;
    return DynamicCost(arr, i, j);
}


int main(){
    int arr3[] = {23, 26, 27, 20};
    int n = sizeof(arr3)/sizeof(arr3[0]);
    memset(mc, -1, sizeof mc);
    cout << "Minimun cost of multiplication is ." << Matrix(arr3, n) << endl;
    return 0;
}