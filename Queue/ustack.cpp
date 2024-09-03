#include<bits/stdc++.h>
using namespace std;


class Queue{
    stack<int> s1;
    stack<int> s2;
    public:

    void enqueue(int v){
        if(!s2.empty()){
          while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
          }
        }
        s1.push(v);
    }

    void dequeue(){
        if(s1.empty() && s2.empty()){
            return;
        } else{
            if(s2.empty()){
                while(!s1.empty()){
                  s2.push(s1.top());
                  s1.pop(); 
                }
            }

            s2.pop();
            return;
        }
    }

    int peek(){
        if(s1.empty() and s2.empty()){
          return -1;
        } else{
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            int top = s2.top();
            return top;
        }
    }

    bool isEmpty(){
       return s1.empty() and s2.empty();
    }

};


int main(){

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();

    cout << q.peek() << endl;

    return 0;
}
