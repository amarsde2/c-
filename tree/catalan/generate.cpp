#include<bits/stdc++.h>
using namespace std;


int generateCatalan(int n){
    if(n<=1) return 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += generateCatalan(i) * generateCatalan(n-i-1);
    }

    return ans;
}


int main(){
    for(int i = 0; i < 10; i++){
       cout << generateCatalan(i) << endl;
    }

    return 0;
}