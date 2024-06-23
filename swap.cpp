#include<iostream>
using namespace std;

int main(){

    /* swap two number without using third variable */

    int x,y;

    cout << "Enter values of x and y : \n";
    cin >> x >> y; 

    x = x + y; 
    y = x - y;
    x = x - y;

    cout << "Swaped values of x and y : "  << x << " and "  << y << endl;
    return 0;
}