#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4] = {1,2,5,6};

    for(int i = 0; i < 4; i++){
        cout << *(arr+i) << endl;
    }

    return 0;
}