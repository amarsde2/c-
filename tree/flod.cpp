#include<bits/stdc++.h>
using namespace std;

void floyd(int b[][3]){
     int i, j, k;

     for(k = 0; k < 3; k++)
     {
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if((b[i][k] * b[k][j] != 0) && (i != j)){
                    if(b[i][k] + b[k][j] < b[i][j] || b[i][j] == 0){
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }


    for(int i = 0; i < 3; i++){
        for (int  j = 0; j < 3; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int b[3][3];
    for(int i = 0; i < 3; i++){
        for (int  j = 0; j < 3; j++)
        {
            b[i][j] = 0;
        }
    }

    b[0][1] = 10;
    b[1][2] = 15;
    b[2][0] = 12;
    
    floyd(b);
    return 0;

}

