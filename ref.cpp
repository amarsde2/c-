#include<iostream>
using namespace std;

void swap(int& x, int& y){

     int tmp = x; 
     x = y ;
     y = tmp;
     
}


int main() {

    int x = 50;
    int y = 100;
  
    swap(x, y);

    cout << x << endl;
    cout << y << endl;

    return 0;

}