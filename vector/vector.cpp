#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};    
    vector<int> points;

    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++){
       points.push_back(arr[i]);
    }

    for(auto v:points){
        cout << v << endl;
    }

    vector<int>:: iterator  it;

    for(it = points.begin(); it != points.end(); it++){
        cout << *it << endl;
    }

    return 0;

}