#include<bits/stdc++.h>
using namespace std;

int main(){
    bool ans = false;
    string str = "(c + (a + b))";
    stack<char> st;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            st.push(str[i]);
        } else if(str[i] == '('){
            st.push(str[i]);
        } else{
            if(str[i] == ')'){
                if(st.top() == '('){
                   ans = true;
                   break;
                }
                while(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                   st.pop();
                }
                st.pop();
            }
        }
    }

    if(ans){
        cout << "Reducent " << endl;
    } else{
        cout << "Not Reucent " << endl;
    }

    return 0;
}