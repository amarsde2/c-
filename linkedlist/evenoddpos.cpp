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


void sortOddEvenPos(Node * &head){
    Node *odd = head;
    Node *even = head->next;
    Node *eventStart = even;

    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = eventStart;

    if(odd->next != NULL){
        even->next = NULL;
    }
   
}

int main(){

    Node *head1 = NULL;
  
   
    insertAtBegin(head1, 29);
    insertAtBegin(head1, 25);
    insertAtBegin(head1, 21);
    insertAtBegin(head1, 17);
    insertAtBegin(head1, 12);
    insertAtBegin(head1, 27);
    insertAtBegin(head1, 24);
    insertAtBegin(head1, 16);
    insertAtBegin(head1, 14);
    insertAtBegin(head1, 11);
    sortOddEvenPos(head1);
    display(head1);

    return 0;
}