#include<bits/stdc++.h>
using namespace std; 

int main(){
    int x[2][2]= {
         {12, 34}, 
         {22, 10}
       };
   int y[2][2] = {
      {3, 4}, 
      {2, 1}
   };
    int z[2][2];

    int m1,m2,m3,m4, m5,m6,m7;

    m1 = (x[0][0] + x[1][0]) * (y[0][0] + y[0][1]);
    m2 = (x[0][1] + x[1][1]) * (y[1][0] + y[1][1]);
    m3 = (x[0][0] - x[1][1]) * (y[0][0] + y[1][1]);

    m4 = (x[0][0]) * (y[0][1] - y[1][1]);
    
    m5 = (x[1][0] + x[1][1]) * (y[0][0]);
    m6 = (x[0][0] + x[0][1]) * (y[1][1]);
    m7 = (x[1][1]) * (y[1][0] - y[0][0]);
   
    z[0][0] =  m2 + m3 - m6 - m7;
    z[0][1] =  m4 + m6;
    z[1][0] = m5 + m7;
    z[1][1] = m1- m3-m4-m5;

    for(int i = 0 ; i < 2; i++){
        for(int j = 0 ; j < 2; j++){
            cout << z[i][j] << " ";
        }
        cout << endl;
    }
}