#include<bits/stdc++.h>
using namespace std;


bool isPaldrim(int num){
    int rev = 0;
    int temp = num;
    while(temp > 0){
        rev = rev * 10 + temp %10;
        temp /= 10;
    }

    return num == rev;
}

int findPalindromstart(vector<int> arr, int k){
    int number = 0;

    for(int i = 0; i < k; i++){
        number = number * 10 + arr[i];
    }
    
    if(isPaldrim(number)){
        return 0;
    }

    for(int i = k; i < arr.size(); i++){
        number =(number % (int) pow(10, k-1))*10 + arr[i] ;
     
        if(isPaldrim(number)){
          return i - k + 1;
        }

    }

    return -1;
}


int main(){
    vector<int> arr = {2,3,5,1,1,5};
    int k = 4;
    int start = findPalindromstart(arr, k);

    if(start == -1){
        cout << "Not found!" << endl;
    } else{
        for(int i = start; i < start + k; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}