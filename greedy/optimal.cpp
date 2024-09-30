#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> files(n);

    for(int i = 0; i < n; i++){
        cin >> files[i];
    }
  
    priority_queue<int, vector<int>, greater<int>> minheap;

    for(int i = 0; i < n; i++){
        minheap.push(files[i]);
    }
    
    int ans = 0;
    while(minheap.size() > 1){
        int f1 = minheap.top();
        minheap.pop();
        int f2 = minheap.top();
        minheap.pop();
        ans += f1 + f2;
        minheap.push(f1+f2);
    }

    cout << ans << endl;

    return 0;

}