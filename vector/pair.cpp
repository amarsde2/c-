#include<bits/stdc++.h>
using namespace std;

bool myCompare(pair<int, int> a, pair<int, int> b){
     
     return a.first < b.first;
} 

int main(){
    vector<pair<int,int>> points;
    int arr[] = {11,1,34,32,12,65,5,4};
    
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
        points.push_back(make_pair(arr[i],i));
    }
    sort(points.begin(), points.end(), myCompare);
    
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        arr[points[i].second] = i;
    }

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << " ";
    }

    return 0;
   
}