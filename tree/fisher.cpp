#include<bits/stdc++.h>
using namespace std;


void fisherYate(vector<char>& arr){
     vector <char> out;
     vector <bool> visited(arr.size(), false);

     for(char i = 0; i < arr.size(); i++){
        int j = rand() % arr.size();
        while(visited[j]){
            j = rand() % arr.size();
        }
        out.push_back(arr[j]);
        visited[j] = true;
     }

     arr = out;
}

int main(){
    vector<char> arr = {'a','b','c','d','e','f'};
    srand(time(NULL));
    fisherYate(arr);

    for(char c: arr){
        cout << c << " ";
    }

    return 0;
}

