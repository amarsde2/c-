#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5+6;
const int INF = 9999;
vector<pair<int, int>> g[N];  // Graph represented as adjacency list
vector<int> dist(N);  // Distance array
vector<int> parent(N);  // Parent array for tracking the MST
vector<int> sz(N);  // Size array for union-find
vector<bool> vist(N, false);  // Visited array to mark processed nodes

// Function to initialize the parent of each node
void make_parent(int v) {
    parent[v] = v;
    sz[v] = 1;
}

// Function to find the parent of a set (with path compression)
int find_set(int v) {
    if (v == parent[v]) 
        return v;
    return parent[v] = find_set(parent[v]);
}

// Function to unite two sets (union by size)
bool unionSet(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(sz[a], sz[b]);
        }
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    } 
    return false;
}

int cost = 0;

// Prim's algorithm to find the MST
void prime(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;
    set<pair<int, int>> s;  // Set to store the (distance, vertex)
    s.insert({0, source});

    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);

        int u = x.second;  // Current node
        int v = parent[u];  // Parent node
        int w = x.first;    // Weight

        vist[u] = true;  // Mark the node as visited
        cout << u << " -> " << v << " -> " << w << endl;  // Print current edge
        cost += w;  // Add weight to the total cost

        // Explore neighbors of the current node
        for (auto it : g[u]) {
            int neighbor = it.first;
            int weight = it.second;

            if (vist[neighbor]) continue;

            // If a better edge is found, update the distance
            if (dist[neighbor] > weight) {
                s.erase({dist[neighbor], neighbor});
                dist[neighbor] = weight;
                s.insert({dist[neighbor], neighbor});
                parent[neighbor] = u;
            }
        }
    }

    cout << "Total cost: " << cost << endl;
}

int main() {
    cin >> n >> m;

    // Initialize the parent for union-find
    for (int i = 0; i < n; i++) {
        make_parent(i);
    }

    // Input the edges of the graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    prime(0);  // Run Prim's algorithm from source node 0
    return 0;
}
