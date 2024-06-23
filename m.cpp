#include<iostream>
using namespace std;

int main(){
    /* write a program to print absolute value of input number */
    int n; 
    cout << "Enter a number: \n";
    cin >> n; 

    if (n >=0) cout << "Ans: " << n << endl;
    else cout << "Ans: " << -n << endl;
   
    return 0;
}