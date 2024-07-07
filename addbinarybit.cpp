#include<iostream>
using namespace std; 


int main(){

    // program to add two binary numbers

    long a,b;
    int sum[20];
    int rem = 0, i = 0;

    cin >> a >> b;

    while( a != 0 || b != 0){
        sum[i++] = (int)((a % 10 + b % 10 + rem) % 2);
        rem = (int)((a % 10 + b % 10 + rem)/2);
        a /= 10;
        b /= 10;
    }

    if(rem != 0){
       sum[i++] = rem;
    }
    
    --i;
    
    while(i >= 0){
        cout << sum[i--];
    }

    cout << endl;

    return 0;
}
