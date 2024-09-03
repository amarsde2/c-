#include<bits/stdc++.h>
using namespace std;

void evalulate(string str){
    stack<int> ms;
    
    for(int i = str.length()-1; i >= 0;i--){
        if(str[i] >= '0' && str[i] <= '9'){
           ms.push(str[i]-'0');
        } else{
            int op1 = ms.top();
            ms.pop();
            int op2 = ms.top();
            ms.pop();
            switch(str[i]){
                case '+': 
                    ms.push(op1+ op2);
                    break;
                case '-':
                    ms.push(op1- op2);
                    break;
                case '*':
                    ms.push(op1* op2);
                    break;
                case '/':
                    ms.push(op1 / op2);
                    break;
            }
        }
    }

    cout << ms.top() << endl;
}


int main(){
    string str = "-+7*45+20";
    evalulate(str);
    return 0;
}

