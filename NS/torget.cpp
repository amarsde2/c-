#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int togent[N];

int main(){
    for(int i = 0; i < N; i++){
       togent[i] = i;
    }

    for(int i = 2; i  < N; i++){
        if(togent[i] == i){
            for(int j = 2 * i; j < N; j+=i){
               togent[j]  *= i-1;
               togent[j] /= i;
            }

            togent[i] = i-1;
        }
    }

    for(int i = 2; i < 11 ; i++){
        cout << togent[i] << endl;
    }

    return 0;
}