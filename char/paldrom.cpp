#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char arr[n+1];
    cin >> arr;

    bool is_valid = true;

    for(int i = 0; i < n; i++){
        
        if(arr[i] != arr[n-i-1]){
            is_valid = false;
            break;
        }
    }

    if(is_valid){
        cout << "valid" << endl;
    } else{
        cout << "invalid" << endl;
    }

    return 0;
}