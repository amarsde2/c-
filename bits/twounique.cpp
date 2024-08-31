#include<bits/stdc++.h>
using namespace std;

bool getBit(int n, int pos){
    return n & (1 << pos);
}

int main(){
    int arr[] = {1,2,3,3,2,4,4,5};
    int n = 8;
    int xeronum = 0;

    for(int i=0; i<n; i++){
        xeronum ^= arr[i];
    }
    int temp = xeronum;

    int pos = 0;
    int setbit = 0;
    while(setbit != 1){
        setbit = xeronum & 1;
        pos++;
        xeronum = xeronum >> 1;
    }

    int newPost = 0;
    for(int i=0; i<n; i++){
       if(getBit(arr[i],pos-1)){
            newPost = newPost ^ arr[i];
       }
    }

    cout << newPost << endl;

    cout << (newPost ^ temp) << endl;
    
    return 0;

}