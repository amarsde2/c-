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
        q1.push(val);
        N++;  
    }

    void pop(){
        if(N > 0){
          while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
          }
          q1.pop();
          queue<int> temp;
          temp = q1;
          q1 = q2;
          q2 = temp;
          N--;
        } else{
            cout << "Queue is empty" << endl;
        }
    }

    int top(){
        if(N > 0){
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }

            int data = q1.front();
            q2.push(data);
            queue<int> temp;
            temp = q1;
            q1 = q2;
            q2 = temp;
        
            return data;

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