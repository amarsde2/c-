#include<bits/stdc++.h>
#include<deque>
using namespace std;


int main(){
    deque<int> q;
    q.push_front(1);
    q.push_front(2);
    q.push_front(3);
    q.push_front(4);
    q.push_back(5);
    q.push_back(6);
    q.push_back(7);
    q.push_back(8);
    
    for(auto i: q){
        cout << i << endl;
    }
}