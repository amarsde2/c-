#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<stdexcept>
using namespace std;

template <class T> 
class Stack{
    private: 
      vector<T> elems;
    public: 
      void push(T const&);
      void pop() ;
      T top() const;
      bool empty() const{
         return elems.empty();
      }
};


template<class T>
void Stack<T>::push(T const& a){
    elems.push_back(a);
}

template<class T>
void Stack<T>::pop(){
    if(elems.empty()){
        throw out_of_range("stack overflow");
    }
    elems.pop_back();
}

template<class T>
T Stack<T>::top() const{
    if(elems.empty()){
        throw out_of_range("stack overflow");
    }
    return elems.back();
}


int main(){
    try{
      Stack<int>    intStack;  // stack of ints 
      Stack<string> stringStack;    // stack of strings 

      intStack.push(7); 
      cout << intStack.top() <<endl; 
      stringStack.push("hello"); 
      cout << stringStack.top() << endl; 
      stringStack.pop(); 
      stringStack.pop(); 

    } catch(exception const& e){
        cout << e.what() << endl;
        return -1;
    }

    return 0;
}