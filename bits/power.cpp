#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 7 ;

    if((n & n-1) == 0){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    // count numbers of 1s in binary form of given number 


    int count = 0;
    while(n){
        count++;
        n  = n  & n-1;
    }

    cout << count << endl;
   
    return 0;

}