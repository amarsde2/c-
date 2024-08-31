#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 100;
    vector<int> prims(n+1, true);

    for(int i = 2; i * i < n;  i++){
        if(prims[i]){
           for(int j = i * i; j <= n; j = j+i){
              prims[j] = false;
           }
        }
    }

    for(int i = 1; i <= n; i++){
        if(prims[i]){
            cout << i << " ";
        }
    }

    cout << endl;
}