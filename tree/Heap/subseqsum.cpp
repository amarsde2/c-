#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    int total;
    cin >>size;
    cin >> total;
    vector<int> a(size);
    for(int i=0; i<size; i++){
        cin >> a[i];
    }

    priority_queue<int, vector<int>> q;

    for(int i=0; i<size; i++){
        q.push(a[i]);
    }

    int sum = 0;
    int count = 0;

    while(!q.empty()){
        sum += q.top();
        q.pop();
        count++;

        if(sum >= total ){
            break;
        }
    }

    if(sum < total){
        cout << "Solution not enough";
        
    } else{
        cout << count << endl;
    }

    return 0;
}