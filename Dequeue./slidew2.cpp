#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> q;
    vector<int> ans;
   
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
  
    for(auto &i : arr){
        cin >> i;
    }

    for(int i = 0; i < k; i++){
        while(!q.empty() && arr[q.back()] < arr[i]){
            q.pop_back();
        }
        q.push_back(i);
    }

    ans.push_back(arr[q.front()]);
   
    for(int i = k;i < n; i++){
        if(q.front() == i - k){
           q.pop_front();
        }
        
        while(!q.empty() && arr[q.back()] < arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(arr[q.front()]);
    }

    for(auto i : ans){
        cout << i << " ";
    }

}