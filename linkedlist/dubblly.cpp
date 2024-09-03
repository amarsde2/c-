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

void insertAtEnd(Node * &head, int key){
    Node *temp = new Node(key);
    Node *ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
}


void insertAfter(Node * &head, int data, int key){
    if(head == NULL){
        insertAtBegin(head, data);
    } 
    Node *temp = new Node(data);
    Node *ptr  = head;
    bool flag = false;
    while(ptr->next != NULL){
        if(ptr->next->data == key){
            flag = true;
            ptr = ptr->next;
            break;
        }
        ptr = ptr->next;
    }

    if(flag == true){
        temp->next = ptr->next;
        
        if(ptr->next != NULL){
           ptr->next->prev = temp;
        } 
        ptr->next = temp;
        temp->prev = ptr;
    } else{
        cout << "Key not found: " << endl;
    }

    return;
}

void deleteAfter(Node * &head, int key){
    if(head == NULL){
        return;
    } 
    Node *temp;
    Node *ptr  = head;
    while(ptr->next != NULL){
        if(ptr->next->data == key){
            temp = ptr->next;
            break;
        }
        ptr = ptr->next;
    }

    if(temp != NULL){
        ptr->next = temp->next;
        temp->next->prev = ptr;
        delete temp;
    }


    return;
}

void display(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main(){

    Node *head = NULL;
    insertAtBegin(head, 24);
    insertAtBegin(head, 23);
    insertAtBegin(head, 22);
    insertAtEnd(head, 25);
    insertAfter(head, 26, 23);
    display(head);
    deleteAfter(head, 23);
    display(head);
    return 0;
}