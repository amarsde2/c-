#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};


class Queue {
    Node *front;
    Node *back;
    public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void push(int val){
        Node * temp = new Node(val);
        if(front == NULL){
            front = temp;
            back = temp;
            return;
        } else{
            back->next = temp;
            back = temp;
        
        }
    }

    bool isEmpty(){
        return front == NULL || front->next == NULL;
    }
    
    void pop(){
        if(!isEmpty()){
            Node *temp = front;
            front = front->next;
            delete temp;
            return;
        } else{
            cout << "Queue is Empty~" << endl;
        }
    }

    int peek(){
        if(!isEmpty()){
            return front->data;
        } else{
            return -1;
        }
    }

    int backItem(){
        if(!isEmpty()){
           return back->data;
        } else{
            return -1;
        }
    }
};


int main(){
    Queue q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    q.pop();
    q.pop();

    cout << q.peek() << endl;

    cout << q.backItem()  << endl;

    return 0;
}

