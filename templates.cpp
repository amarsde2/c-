#include<iostream>
#include<string>
using namespace std;

template <typename T>  
T const& maxT(T const& a, T const& b){
  return a > b ? a : b;
}


int main(){
    int a = 5, b = 6;
    cout << maxT(a,b) << endl;
    string c = "Af";
    string d = "fA";
    cout << maxT(c,d) << endl;

    float x = 3.5, y = 4.5;

    cout << maxT(x,y) << endl;

    return 0;
}