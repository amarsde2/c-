#include<bits/stdc++.h>
using namespace std;
#define inf 99999
int n = 3;
int cost[3][3] = {{0, 10, 20}, {12, 0, 15}, {16, 18, 0}};
int p[9] = {0};

int min_cost = 0;

int applyfind(int i){
    while(p[i] != 0){
        i = p[i];
    }
    return i;
}

int apply(int i, int j){
    if(i != j){
        p[j] = i;
        return 1;
    }
    return 0;
}

void kurkal(){
    int ne = 1;
    int a,b,i,j, u,v;
    

    while(ne < n){
        int minC = inf;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(cost[i][j] < minC){
                    minC = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        
        u = applyfind(u);
        v = applyfind(v);

        if(apply(u, v) != 0){
            cout << a << " -> " << b << endl;
            min_cost += minC;
        }
        cost[a][b] = cost[b][a] = inf;
        ne++;
    }
}

int main(){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cost[i][j] == 0){
                cost[i][j] = inf;
            }
        }
    }

    kurkal();

    cout << min_cost << endl;

}





