#include<bits/stdc++.h>
using namespace std;
int n = 50;
vector<bool> prims(n+1, true);

int main(){
    for(int i = 2; i * i <= n; i++){
        if(prims[i] == true){
            for(int j =  i *i; j <= n; j+= i){
               prims[j] = false;        
            }
        }
    }

    for(int i = 0; i <= n; i++){
        if(prims[i] == true){
            cout << i << " ";
        }
    }
}