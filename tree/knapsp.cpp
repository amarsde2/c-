#include<bits/stdc++.h>
using namespace std;
#define V 5
int p[] = {10, 15, 10, 12, 8};
int w[] = {3, 3, 2, 5, 1};
int W = 10; 

int main(){
    int used[V];
    for(int i = 0 ; i < V ; ++i){
        used[i] = 0;
    }
    float profit = 0;
    int cw = W;
    while(cw > 0){
       int minIf = -1;
       for(int i= 0; i < V ; ++i){
          if(used[i] == 0 && ((minIf == -1) || (float) p[i]/w[i] > p[minIf]/w[minIf])){
             minIf =i;
          }
       }

       used[minIf] = 1;
       cw -= w[minIf];
       profit += p[minIf];

       if(cw >= 0){
          printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", minIf + 1, w[minIf], p[minIf], cw);
       } else{
          printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)((1 + (float)cw/w[minIf]) * 100), p[minIf], w[minIf], minIf + 1);
          
          profit -= p[minIf];
          profit =  (float)profit +  (float)(1 + (float) cw/w[minIf]) * p[minIf];
       }
    }

    cout << "total profit " << profit << endl;

    return 0;
}

