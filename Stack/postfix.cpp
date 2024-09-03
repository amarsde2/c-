#include<bits/stdc++.h>
using namespace std;

void evalulate(string str){
    stack<int> ms;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            ms.push(str[i]-'0');
        } else{
            int op2 = ms.top();
            ms.pop();
            int op1 = ms.top();
            ms.pop();

            switch(str[i]){
                case '+': 
                    ms.push(op1 + op2);
                    break;
                case '-':
                    ms.push(op1 - op2);
                    break;
                case '*':
                    ms.push(op1 * op2);
                    break;
                case '/':
                    ms.push(op1 / op2);
                    break;
                default:
                    break;
            }
        }
    }

    cout << ms.top() << endl;
}


int main(){
    string str = "46+2/5*7+";
    evalulate(str);
    return 0;
}

