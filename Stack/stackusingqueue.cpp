#include<bits/stdc++.h>
using namespace std;


class Stack {
    int N;
    queue<int>q1;
    queue<int>q2;
    public:
    Stack(){
        N = 0;
    }
    void push(int val){
        q2.push(val);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        N++;
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;    
    }

    void pop(){
        if(N > 0){
          q1.pop();
          N--;
        } else{
            cout << "Queue is empty" << endl;
        }
    }

    int top(){
        if(N > 0){
           return q1.front();
        } else{
            return -1;
        }
    }

    int size(){
        return N;
    }
};


int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    cout << st.size() << endl;
    st.pop();

    cout << st.top() << endl;
}