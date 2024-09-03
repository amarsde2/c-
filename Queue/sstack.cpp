#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1;

public:
    // Enqueue element into the queue
    void enqueue(int v) {
        s1.push(v);
    }

    // Dequeue element from the queue
    void dequeue() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        // Get the bottom element of the stack
        int topElement = s1.top();
        s1.pop();

        if (s1.empty()) {
            // The bottom element is the front of the queue
            return;
        }

        // Recursively call dequeue to reach the bottom element
        dequeue();

        // Push the top element back after reaching the bottom
        s1.push(topElement);
    }

    // Get the front element of the queue
    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int topElement = s1.top();
        s1.pop();

        if (s1.empty()) {
            // The bottom element is the front of the queue
            s1.push(topElement);  // Restore stack state
            return topElement;
        }

        // Recursively call peek to reach the bottom element
        int front = peek();

        // Push the top element back after reaching the bottom
        s1.push(topElement);

        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << q.peek() << endl;  // Output should be 4, as 1, 2, 3 are dequeued

    return 0;
}
