#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  
    cin >> n;
    int Arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> Arr[i];
    }
     
    int N  = 1e6+2;
    int A[N];

    for(int i = 0; i < N; i++){
        A[i] = -1;
    }
    
    int minIndex = INT_MAX;

    for(int i = 0; i < n; i++){
        if(A[Arr[i]] > -1){
           minIndex = min(minIndex, A[Arr[i]]);
           A[Arr[i]] = i;
        } else{
           A[Arr[i]] = i;
        }
    }
    
    cout << "Min Duplicate index " << minIndex + 1 <<  endl;

    return 0;
}
