#include <iostream>
#include <string>
#include <cctype>
#include <stack>

std::stack<char> stack;

void push(char ch){
    stack.push(ch);
}

char pop(){
    char top = stack.top();
    stack.pop();
    return top;
}

int precedence(char ch){

   switch(ch){
      case '+':
      case '-':
         return 2;
      case '*':
      case '/':
         return 3;
      case '^':
         return 4;
      case '(':
      case ')':
      case '#':
         return 1;
      default:
          return 0;
   }
   return 0;
}

int isOperator(char ch){
    switch(ch){
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '(':
      case ')':
         return 1;
      default:
          return 0;
   }
   return 0;
}


void convert(const std::string& infix, std::string& postfix) {
    int j = 0;
    stack.push('#');
    for (char symbol : infix) {
        if (isOperator(symbol) == 0) {
            postfix += symbol;
            j++;
        } else {
            if (symbol == '(') {
                push(symbol);
            } else {
                if (symbol == ')') {
                    while (stack.top() != '(') {
                        postfix += pop();
                        j++;
                    }
                    stack.pop(); // pop out '('
                } else {
                    if (precedence(symbol) > precedence(stack.top())) {
                        push(symbol);
                    } else {
                        while (precedence(symbol) <= precedence(stack.top())) {
                            postfix += pop();
                            j++;
                        }
                        push(symbol);
                    }
                }
            }
        }
    }

    while (stack.top() != '#') {
        postfix += pop();
        j++;
    }

    postfix[j] = '\0'; // null terminate string
}

int evaluate(const std::string& postfix){
    std::stack<int> stack_int;

    for(char c : postfix){
        if(isOperator(c) == 0){
            stack_int.push(c - '0');
        } else{
            int a = stack_int.top();
            stack_int.pop();
            int b = stack_int.top();
            stack_int.pop();

            switch (c)
            {
              case '+':
                  stack_int.push(a + b);
                  break;
              case '-':
                  stack_int.push(a - b);
                  break;
              case '*':
                  stack_int.push(a * b);
                  break;
              case '/':
                  stack_int.push(a/b);
                  break;
            }
        }

    }

    return stack_int.top();
}

int main(){
    std::string infix = "1*(2+3)";
    std::string postfix;
    convert(infix, postfix);
    std::cout << postfix << std::endl;
    std::cout << evaluate(postfix) << std::endl;
    return 0;
}
