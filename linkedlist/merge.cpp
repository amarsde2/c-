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

Node * mergeTwoSortedLinkedList(Node * &head1, Node *&head2){
   
    Node *ptr3,  *ptr2, *ptr1;
    ptr1 = head1;
    ptr2 = head2;
    Node *dummyNode = new Node(-1);
    ptr3 = dummyNode;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        } else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }


    while(ptr1 != NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while(ptr2 != NULL){
       ptr3->next = ptr2;
       ptr2 = ptr2->next;
       ptr3 = ptr3->next;
    }

    return dummyNode->next;
}

Node * mergeRecursive(Node *&head1, Node *&head2){
       if(head1 == NULL){
        return head2;
       }
       if(head2 == NULL){
        return head1;
       }

       Node *ptr3;

        if(head1->data < head2->data){
           ptr3 = head1;
           ptr3->next = mergeRecursive(head1->next, head2);
        
        } else{
           ptr3 = head2;
           ptr3->next = mergeRecursive(head1, head2->next);
        }

    
        return ptr3;

}

int main(){

    Node *head1 = NULL;
    Node *head2 = NULL;
   
    insertAtBegin(head1, 29);
    insertAtBegin(head1, 25);
    insertAtBegin(head1, 21);
    insertAtBegin(head1, 17);
    insertAtBegin(head1, 12);
    insertAtBegin(head2, 27);
    insertAtBegin(head2, 24);
    insertAtBegin(head2, 16);
    insertAtBegin(head2, 14);
    insertAtBegin(head2, 11);
    
    Node* head3 = mergeTwoSortedLinkedList(head1, head2);
    display(head3);

    return 0;
}