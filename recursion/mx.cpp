#include<bits/stdc++.h>
using namespace std;

string unique(string value){
   
   if(value.length() == 0) return "";

   char c = value[0];
   string rm = unique(value.substr(1));
   if(c  == 'x'){
      return rm + 'x';
   } else{
      return c + rm;
   }
}


int main(){
    string str = "xabcxded";

    cout << unique(str) << endl;

    return 0;
}