#include<bits/stdc++.h>
using namespace std;

int knapscap(int values[], int w[], int n, int W){

    if(n == 0) return 0;

    if(w[n-1] > W){
        return knapscap(values, w, n-1, W);
    }

    return max(knapscap(values, w, n-1, W),  knapscap(values, w, n-1, W - w[n-1]) + values[n-1]);
}


int main(){
    int vales[] = {100, 50,150};
    int w[] = {10, 20, 30};
    int W = 50;
    int n = 3;
     
    cout << knapscap(vales, w, n,W) << endl;

    return 0;
}