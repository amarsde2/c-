#include<bits/stdc++.h>
using namespace std;
#define V 6
#define inf 99999


int findAdj(int dist[], int mSet[]){
    int minCost = inf;
    int ind = -1;
    for(int i=0; i<V; i++){
        if(mSet[i] == false && dist[i] < minCost){
           ind = i;
           minCost = dist[i];
        }
    }

    return ind;
}

void primeMinium(int graph[V][V], int parent[]){
     int dist[V];
     int mSet[V];
     for(int i = 0; i < V;i++){
        mSet[i] = false;
        dist[i] = inf;
     }
     parent[0] = -1;

     dist[0] = 0;
    
     for(int i = 0; i < V-1; i++){
          int m = findAdj(dist, mSet);
          mSet[m] = true;
          for(int j = 0; j < V; j++){
            if(graph[m][j] && mSet[j] == false && graph[m][j] < dist[j]){
                 parent[j] = m;
                 dist[j] = graph[m][j];
            }
          }
     }

}

void preorder(int parent[V]){
    cout << "Preorder traversal of parent -> " << endl;

    for(int i = 1; i < V; i++){
        cout << parent[i] << " -> ";
    }

    cout << endl;
}

void tspApproximation(int grap[V][V]){
    int parent[V];
    int root = 0;
    primeMinium(grap, parent);
    preorder(parent);

    for(int i = 0; i < V; i++) {
       cout << parent[i] << " -> ";
    }

     cout << root << " → " << parent[0] << endl;
    cout << endl;

    cout << "Minimum cost: " << endl;
 
    int mincost = 0;
 
    for(int i = 1; i < V; i++) {
        mincost += grap[parent[i]][i];
    }

    cout << mincost << endl;
 
}

int main(){
    int graph[V][V] = {
      {0, 3, 1, 6, 0, 0},
      {3, 0, 5, 0, 3, 0},
      {1, 5, 0, 5, 6, 4},
      {6, 0, 5, 0, 0, 2},
      {0, 3, 6, 0, 0, 6},
      {0, 0, 4, 2, 6, 0}
   };
   tspApproximation(graph);
   return 0;
}