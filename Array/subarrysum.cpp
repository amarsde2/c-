#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n;
    cin >> k; 
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int start = 0; 
    int sum = 0;
    int j = 0;
  
    while( j < n){

        if(sum == k){
            cout << start+1 <<  " - " << j << endl;
            return 0; 
        } 

        sum += arr[j];
        
        if(sum > k){
           sum  -= arr[start];
           start++;
        
        }

        j++;
    }

    cout << "Not found! \n";
    return 0;
}