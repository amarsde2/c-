#include<bits/stdc++.h>
using namespace std;

/**
 * @brief implmenation of queue data structure
 * @author Amar kumar
 * @cite  Software Engineer
 */

class Queue{
    int *arr;
    int totalItems;
    int front;
    int back;
    int size;
    public:
    Queue(int n){
        size = n;
        totalItems = 0;
        front = 0;
        back = -1;
        arr = new int[size];
    }

    bool isFull(){
        return totalItems == size;
    }

    bool isEmpty(){
        return totalItems == 0;
    }

    void push(int val){
        if(!isFull()){
            if(back == size){
                back = -1;
            }
            arr[++back] = val;
            totalItems++;
        } else{
            cout << "Queue capacity is over" << endl;
        }
    }

    int pop(){
        if(!isEmpty()){
            int key = arr[front++];          
            if(front == size){
                front = 0;
            }
            totalItems--;
            return key;
        } else{
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    int peek(){
        if(!isEmpty()){
           return arr[front];
        } else{
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    int backe(){
        if(!isEmpty()){
           return arr[back];
        } else{
            cout << "Queue is empty" << endl;
            return -1;
        }
    }
};


int main(){
    Queue myqueue(10);

    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(3);
    myqueue.push(4);
    myqueue.push(5);
    myqueue.push(6);
    myqueue.push(7);
    myqueue.push(8);
    myqueue.push(9);
    myqueue.push(10);
    myqueue.push(11);

    cout << myqueue.pop() << endl;
    cout << myqueue.pop() << endl;
    cout << myqueue.pop() << endl;
    cout << myqueue.pop() << endl;
    cout << myqueue.pop() << endl;

    cout << myqueue.peek() << endl;
    cout << myqueue.backe() << endl;


    return 0;

}