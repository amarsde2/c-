#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2,1,3,2,3,1,5,6,7,6,7};
    int xer = 0;

    for(int i=0; i < 11; i++){
        xer = xer ^ arr[i];
    }

    cout << xer << endl;

    return 0;
}