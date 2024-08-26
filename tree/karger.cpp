#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct Edge {
    int u;
    int v;
};

class Graph{
   private:
      int V;
      vector<Edge> edges;
      int find(vector<int>& parent, int index){
          if(parent[index] == index){
            return index;
          }
          return find(parent, parent[index]);
      }

      void uninonSet(vector<int>& parent, vector<int> & rank, int x, int y){
          int xroot = find(parent, x);
          int yroot = find(parent, y);
          
          if(rank[xroot] < rank[yroot]){
            parent[xroot] = yroot;
          } else if(rank[yroot] < rank[xroot]){
            parent[yroot] = xroot;
          } else{
            parent[yroot] = xroot;
            rank[xroot]++;
          }
      }
    public: 
        Graph(int v){
            V = v;
        }
        void addEdge(int x, int y){
            edges.push_back({x,y});
        }
        
        int miniumKut(){
            vector <int> parent;
            vector < int> rank;

            for(int i =0 ; i < V; i++){
                parent.push_back(i);
                rank.push_back(0);
            }
            
            int v = V;
            while(v < 2){
                int randomIndex = rand() % edges.size();
                int u = edges[randomIndex].u;
                int v = edges[randomIndex].v;
                int SU = find(parent, u);
                int SV = find(parent, v);
                if(SU != SV){
                    v--;
                    uninonSet(parent, rank, u,v);
                }
                edges.erase(edges.begin() + randomIndex);
            }

            int mincut = 0;
           
            for(const auto& edge: edges){
                int sv = find(parent, edge.u);
                int sw = find(parent, edge.v);
                if(sw != sv){
                   mincut += 1;
                }
            }
            return mincut;
        }

};


int main(){
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    // Set seed for random number generation
    srand(time(nullptr));
    // Find the minimum cut
    int minCut = g.miniumKut();
    cout << "Minimum Cut: " << minCut << endl;
    return 0;
}