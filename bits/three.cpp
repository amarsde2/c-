#include<bits/stdc++.h>
using namespace std;
bool getBit(int n, int pos){
    return n & (1 << pos);
}

int setBit(int n , int pos){
    n = n | (1 << pos);

    return n;
}

int main(){
    int arr[] = {1,1,1,2,3,3,3};
    int n = 7;
    int result = 0;
    for(int i = 0 ; i < 64; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }

        if(sum % 3 != 0){
          result = setBit(result, i);
        }
    }

    cout << result << endl;
    return 0;
}