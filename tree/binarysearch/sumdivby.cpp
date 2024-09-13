#include<bits/stdc++.h>
using namespace std;



void findSubsquenearray(vector<int> arr, int k){
    int sum = 0;
    int start =  0;
    pair<int, int> p;
    bool found = false;
    for(int i = 0; i < k; i++){
       sum += arr[i];
    }

    if(sum % 3 == 0){
       found = true;
       p = {0, k-1};
    }

    for(int i = k; i < arr.size(); i++){
        if(found){
            break;
        }
        sum += arr[i] - arr[start++];
        if(sum % 3 == 0){
           p = {start , i};
           found  = true;
           break;
        }
    }   

    if(found){
       for(int i = p.first; i <= p.second; i++){
           cout << arr[i] << " ";
       }  
       cout << endl;
    } else{
        cout << "Not found!" << endl;
    }
}


int main(){
    vector<int> arr = {84,23,45,12,56,82};
    int k = 3;
    
   
    findSubsquenearray(arr, k);
}