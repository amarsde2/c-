#include<bits/stdc++.h>
using namespace std;

int countPath(int s, int d){
    if(s == d){
      return 1;
    }

    if(s > d){
        return 0;
    }

   int count = 0;

   for(int i = 1; i <= 6; i++){
      count += countPath(s+i, d);
   }
   
   return count;
}

int main(){

    cout << countPath(0, 3) << endl;
    return 0;
}