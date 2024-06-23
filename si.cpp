#include<iostream> 
using namespace std;

int main(){

    /* program to calculate simple interest */
    float p, n, r, si;

    cout << "Enter amount: \n";
    cin >> p;

    cout << "Enter numbers of years: \n";
    cin >> n;

    cout << "Enter interest rate: \n"; 
    cin >> r;

    si = (p * n * r) / 100; 

    cout << "Simple interest is : " << si << endl;

    return 0;

}