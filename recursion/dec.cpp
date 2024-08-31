#include<bits/stdc++.h>
using namespace std;


void disPlay(int n){
    
    if(n == 0) return;
    cout << n << endl;
    disPlay(n-1);
    
}

void increase(int n){
    if(n == 0) return;

    increase(n-1);
    cout << n << endl;     
}



int main(){
    int n = 10;
    disPlay(n);
    increase(n);
    return 0;
}