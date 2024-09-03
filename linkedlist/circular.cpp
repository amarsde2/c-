#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node(int value){
        data = value;
        next = NULL;
    }
};


void insertAtBeginning(Node * &head, int key){
    Node *temp = new Node(key);
    Node *last  = head;
    if(head == NULL){
        head = temp;
        head->next = head;
    } else{
        while(last->next != head){
           last = last->next;
        }
        last->next = temp;
        temp->next = head;
        head = temp;
    }  
}

void insertAtEnd(Node * &head, int key){
    Node *temp = new Node(key);
    Node *last = head;
    if(head == NULL){
        head = temp;
        head->next = head;
    } else{
        
        while(last->next != head){
           last = last->next;
        }
    
        last->next = temp;
        temp->next = head;
    } 
}

void deleteAtBeginning(Node * &head){
    Node *temp = head;
    Node *deleteNode;

    if(head->next == head){
        deleteNode = head;
        head = NULL;
        delete deleteNode;
    }
    while(temp->next != head){
        temp = temp->next;
    }
    deleteNode = head;
    head = head->next;
    temp->next = head;
  
    delete deleteNode;
}

void deleteAtEnd(Node * &head){

    Node *temp = head;
    Node *deleteNode;

    if(head->next == head){
        deleteNode = head;
        head = NULL;
        delete deleteNode;
    }
    while(temp->next->next != head){
        temp = temp->next;
    }
    deleteNode = temp->next;
    temp->next = head;
    delete deleteNode;
}

void display(Node * &head){
    Node *temp = head;
    do{
     cout << temp->data << " ";
     temp = temp->next;
    } while(temp != head);
   
    cout << endl;
}

int main(){
    Node *head = NULL;
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 9);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 7);
    insertAtEnd(head, 11);
    display(head);
    deleteAtEnd(head);
    display(head);
    deleteAtBeginning(head);
    display(head);

    return 0;
}