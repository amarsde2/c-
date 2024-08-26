#include<iostream>
#define inf 999999
#define MAX 10
using namespace std;
int G[MAX][MAX] = {
   {0, 19, 8},
   {21, 0, 13},
   {15, 18, 0}
};
int S[MAX][MAX], n;

int prims();
int main(){
   int i, j, cost;
   n = 3;   
   cost=prims();   
   cout <<"Spanning tree:";
   for(i=0; i<n; i++) {
      cout << endl;
      for(j=0; j<n; j++)
         cout << S[i][j] << " ";
   }
   cout << "\nMinimum cost = " << cost;
   return 0;
}

int prims(){
    int ne;
    int C[MAX][MAX],u,v,cost,min_cost, visited[MAX],dist[MAX],from[MAX];
    for(int i = 0 ; i < n;i++){
        for(int j = 0; j < n; j++){
            if(G[i][j] == 0){
                C[i][j] = inf;
            } else{
                C[i][j] = G[i][j];
            }
            S[i][j] = 0;
        }
    }

    visited[0] = 1;
    dist[0] = 0;
    for(int i = 1; i < n; i++){
        dist[i] = C[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    
    ne = n-1;

    while(ne > 0){
        min_cost = inf;

        for(int i = 1; i < n; i++){
            if(visited[i] == 0 && dist[i] < min_cost){
               min_cost = dist[i];
               v = i;
            }
        }

        u = from [v];

        S[u][v] = dist[v];
        S[v][u] = dist[v];
 
        ne--;

        visited[v] = 1;


        for(int i = 1; i < n; i++){
            if(visited[i] == 0 && C[i][v] < dist[i]){
                dist[i] = C[i][v];
                from[i] = v;
            }
        }

        cost += C[u][v];

    }
    return cost;
}