#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node *next;
   Node *prev;

   Node(int value){
    data = value;
    next = NULL;
    prev = NULL;
   }
};


void insertAtBegin(Node * &head, int key){
    Node *temp = new Node(key);
    temp->next = head;
    if(head != NULL){
      head->prev = temp;
    }
    head = temp;
}



void display(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int getLength(Node * head){
    int count = 0;
    Node *ptr = head;

    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}
Node * appendKNode(Node * head, int k){
    int len = getLength(head);
    
    k = k % len;

    Node* tail = head;
    Node* newHead;
    Node* newtail;
   
    int count = 1;
    
    while(tail->next != NULL){
        if(count == len - k){
            newtail = tail;
        }       

        if(count  == len - k + 1){
            newHead = tail;
        }

        count++;
        tail = tail->next;
    }

    newtail->next = NULL;
    tail->next = head;
    return newHead;

}

int main(){

    Node *head = NULL;
    Node *newHead;
    insertAtBegin(head, 24);
    insertAtBegin(head, 23);
    insertAtBegin(head, 22);
    insertAtBegin(head, 21);
    insertAtBegin(head, 20);
    insertAtBegin(head, 19);
    insertAtBegin(head, 18);
    insertAtBegin(head, 17);
    insertAtBegin(head, 16);
    display(head);
    newHead = appendKNode(head,5);
    display(newHead);
    return 0;
}