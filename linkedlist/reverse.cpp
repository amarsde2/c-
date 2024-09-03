#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node *next;

   Node(int value){
      data = value;
      next = NULL;
   }
};

void insertAtBeginner(Node* &head, int value){
    Node * temp = new Node(value);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &head, int value){
    Node *temp = new Node(value);
    Node *ptr = head;

    if(head == NULL){
        head = temp;
    }

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = temp;
    
}

void display(Node * head){
 
    Node *ptr = head;
    while(ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node* reverse(Node * head){
    Node *previous = NULL;
    Node *current = head;
    Node *nextptr;

    while(current != NULL){
        nextptr = current->next;
        current->next = previous;   
        previous = current;
        current = nextptr;
    }

    return previous;
}

Node* recursive(Node * head){
      Node *newHead;
      
      if(head == NULL || head->next == NULL){
        return head;
      }
      
      newHead = recursive(head->next);
      head->next->next = head;
      head->next = NULL;

      return newHead;

}


Node *reverseKNode(Node *head, int k){
    Node * prev = NULL;
    Node* current=  head;
    Node* nextptr;
    int count = 0;
    while(current != NULL && count < k){
        nextptr = current->next;
        current->next = prev;
        prev = current;
        count++;
        current = nextptr;
    }

    if(nextptr != NULL){
        head->next = reverseKNode(nextptr, k);
    }
    
    return prev;
}

int main(){
    Node *head = NULL;
    insertAtBeginner(head, 23);
    insertAtBeginner(head, 25);
    insertAtBeginner(head, 75);
    insertAtEnd(head, 29);
    display(head);
    head = reverseKNode(head,2);
    cout << "Reverse string " << endl;
    display(head);
    return 0;
}