#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    switch(ch){
        case '^':
           return 3;
        case '*':
        case '/':
           return 2;
        case '+':
        case '-':
           return 1;
        default:
           return -1;
    }
}

string convertInfixToPrefix(string str){
     
       stack<char> st;
       string result ="";
       for(int i = 0; i < str.length(); i++){
          if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
          {
            result += str[i];

          } else if(str[i] == '('){
            st.push(str[i]);
          } else if(str[i] == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
          } else {

            while(!st.empty() && precedence(st.top()) >= precedence(str[i])){
                result += st.top();
                st.pop();
            }

            st.push(str[i]);
          }
       }

        while(!st.empty()){
          result += st.top();
          st.pop();
        }
        
       
         
        return result;
}




int main(){
    cout << convertInfixToPrefix("(a-b/c)*(a/k-l)") << endl;
    return 0;
}