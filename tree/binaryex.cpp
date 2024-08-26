#include<bits/stdc++.h>
using namespace std;

int binaryEx(int num, int exp){
    int output = 1;

    while (exp > 0){
       
       if(exp % 2 == 1){
          output = output * num;
       }

       num = num *num;

       exp = exp/2;

    }

    return output;
}


int main(){
    int num = 2;
    int pow = 5;

    cout << binaryEx(2,5);

    return 0;
}