#include<iostream>
using namespace std; 

int main(){
    
    /* calculate volumne of a sphere */
    /* volumne of sphere = (4/3)PI*r*r*r  */
    
    const float PI = 3.14;
    float radius, vos;

    cout << "Enter radius of sphere: \n";

    cin >> radius;

    vos = (4/3) * PI * radius * radius * radius;

    cout << "Enter volumne of sphere: " << vos <<endl;

    return 0;
}