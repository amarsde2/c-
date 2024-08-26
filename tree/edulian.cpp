#include<bits/stdc++.h>
using namespace std;


int getComdiv(int a , int b){
    if(b == 0){
        return a;
    } else{
       return getComdiv(b, a%b);
    }
}

int main(){
    int a = 52;
    int b = 28;
 
    cout << getComdiv(a, b);
}