#include<bits/stdc++.h>
using namespace std;

bool isValid(string str){
    stack<char> st;

    for(int i=0; i<str.length(); i++){

        if(str[i] == '[' || str[i] == '{' || str[i] == '('){
            st.push(str[i]);
        } else{
            char top = st.top();
            if(!st.empty() && ((top == '(' && str[i] == ')') ||
               (top == '{' && str[i] == '}') || 
               (top == '[' && str[i] == ']')))
            {
               st.pop();
            }  else{
                return false;
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return true;
}

int main(){
    string str = "[{()}]";
    if(isValid(str)){
        cout << "String is valid: " << endl;
    } else{
        cout << "String is not valid: " << endl;
    }

    return 0;
}
