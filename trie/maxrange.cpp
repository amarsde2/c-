#include<bits/stdc++.h>
using namespace std;
const int int_size = 31; // Maximum bit length for 32-bit integers

class Node {
public:
    Node *next[2];
    Node() {
        next[0] = next[1] = NULL; // Initialize both children as NULL
    }
};

Node *trie;

void insert(int n) {
    Node *it = trie;
    for (int i = int_size - 1; i >= 0; i--) {
        int bit = (n >> i) & 1; // Extract i-th bit from number n
        if (!it->next[bit]) {
            it->next[bit] = new Node(); // Create new node if it doesn't exist
        }
        it = it->next[bit]; // Move to the next node
    }
}

int query(int n) {
    Node *it = trie;
    int ans = 0;
    for (int i = int_size - 1; i >= 0; i--) {
        int curBit = (n >> i) & 1;
        if (it->next[curBit ^ 1]) { // Try to take the opposite bit
            ans |= (1 << i); // Set the bit in the answer
            it = it->next[curBit ^ 1]; // Move to the opposite bit node
        } else {
            it = it->next[curBit]; // Move to the current bit node
        }
    }
    return ans;
}

void deleteTrie(Node *node) {
    if (!node) return;
    deleteTrie(node->next[0]);
    deleteTrie(node->next[1]);
    delete node;
}

int main() {
    trie = new Node(); // Initialize the Trie root
    int n;
    cin >> n; // Read the size of the array
    vector<int> a(n); // Array to store the elements
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read each element into the array
    }
    
    vector<int> rmax(n + 1, 0); // Array to store max XOR for suffixes
    int r = 0; // Variable to store the current suffix XOR

    // Build Trie for suffix XORs and compute rmax[]
    insert(0); // Insert the base case (XOR of an empty subarray)
    for (int i = n - 1; i >= 0; i--) {
        r ^= a[i]; // Compute the XOR from index i to n-1
        rmax[i] = max(rmax[i + 1], /* The `query` function in the provided code is used to find the
        maximum XOR value that can be obtained by taking the XOR of a
        given number `n` with any number present in the Trie data
        structure. */
        query(r)); // Query Trie for max XOR
        insert(r); // Insert the current suffix XOR into the Trie
    }

    // Reset the Trie for prefix XORs
    deleteTrie(trie); 
    trie = new Node();
    insert(0); // Insert the base case (XOR of an empty subarray)

    int ans = 0;
    int l = 0; // Variable to store the current prefix XOR

    // Calculate max XOR by considering both prefix and suffix
    for (int i = 0; i < n - 1; i++) { // Ensure we stop before the end
        l ^= a[i]; // Compute the XOR from 0 to i
        ans = max(ans, rmax[i + 1] + query(l)); // Max XOR for non-overlapping subarrays
        insert(l); // Insert the current prefix XOR into the Trie
    }

    cout << ans << endl; // Output the final answer

    deleteTrie(trie); // Clean up the Trie
    return 0;
}
