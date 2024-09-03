#include<bits/stdc++.h>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& mystack, int ele){
    if(mystack.empty()){
       mystack.push(ele);
       return;
    }
    int topel = mystack.top();
    mystack.pop();
    insertAtBottom(mystack, ele);
    mystack.push(topel);
}

void reverse(stack<int> &mystack){ 
    if(mystack.empty()){
        return;
    }
    int topel = mystack.top();
    mystack.pop();
    reverse(mystack);
    insertAtBottom(mystack,topel);   
    return;

}

void display(stack<int> mystack){
    while(!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    } cout << "\n";
}

int main(){
    stack<int> mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    mystack.push(6);
    display(mystack);
    reverse(mystack);
    display(mystack);
    return 0;
}