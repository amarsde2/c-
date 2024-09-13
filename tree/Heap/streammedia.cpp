#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pmax;
priority_queue<int, vector<int>, greater<int>> pmin;


void insert(int data){
    if(pmax.size() == pmin.size()){
        if(pmax.size() == 0){
          pmax.push(data);
          return;
        }

        if(data < pmax.size()){
            pmax.push(data);
        } else{
            pmin.push(data);
        }

    } else{
         
       if(pmax.size() > pmin.size()){
            if(data >=  pmax.top()){
              pmin.push(data);
            } else{
                int x = pmax.top();
                pmax.pop();
                pmax.push(data);
                pmin.push(x);
            }
       } else{
            if(data <= pmin.top()){
               pmax.push(data);
            } else{
               int x = pmin.top();
               pmin.pop();
               pmax.push(x);
               pmin.push(data);
            }
       }
    }
}

double findMeadian(){
    if(pmax.size() == pmin.size()){
        return (pmin.top() + pmax.top()) / 2.0;
    } else{
        if(pmax.size() > pmin.size()){
           return pmax.top();
        } else{
           return pmin.top();
        }
    }
}

int main(){
    insert(10);
    cout << findMeadian() << endl;
    insert(15);
    cout << findMeadian() << endl;
    insert(20);
    cout << findMeadian() << endl;
    insert(25);
    cout << findMeadian() << endl;
    insert(30);
    cout << findMeadian() << endl;

    return 0;
}