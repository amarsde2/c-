#include<bits/stdc++.h>
using namespace std;
#define MAX 3

int G[MAX][MAX] = {
   {0, 19, 8},
   {21, 0, 13},
   {15, 18, 0}
};

int S[MAX][MAX] = {};

int cost = 0;

int visited[MAX];



void minSpan(int v){
    visited[v] = 1;
    int mincost = 999, adj = 999;

    for(int i = 0; i < MAX; i++){
        if(visited[i] == 0 && mincost > G[v][i]){
            mincost = G[v][i];
            adj = i;
        }
    }

    if(mincost != 999){
        cost  += mincost;
        S[v][adj] = mincost;
        S[adj][v] = mincost;
    }
    
    if(adj == 999){
        return;
    }

    minSpan(adj);
} 


int main(){
    for(int i = 0 ; i < MAX; i++){
        visited[MAX] = 0;
    }

    for(int i = 0 ; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            S[i][j] = 0;
        }
    }

    minSpan(0);

    cout << "Minimum spanning ... " << endl;
    for(int i = 0 ; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout << S[i][j] << " ";
        }
        cout << endl;
    }

     cout << "Minimum spanning cost ... "  << cost << endl;
}