#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int a  = 4, b = 5;

    swap(&a,&b);

    cout << "a = " << a << " b = " << b << endl;

    return 0;
}