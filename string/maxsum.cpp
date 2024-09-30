#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent the nodes in the segment tree
struct SegmentTreeNode {
    int sum, prefixSum, suffixSum, maxSum;

    SegmentTreeNode() : sum(0), prefixSum(0), suffixSum(0), maxSum(0) {}
};

// Function to merge two segment tree nodes
SegmentTreeNode merge(SegmentTreeNode left, SegmentTreeNode right) {
    SegmentTreeNode parent;
    parent.sum = left.sum + right.sum;
    parent.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
    parent.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
    parent.maxSum = max({left.maxSum, right.maxSum, left.suffixSum + right.prefixSum});
    return parent;
}

// Build the segment tree
void buildTree(vector<SegmentTreeNode>& tree, const vector<int>& arr, int start, int end, int node) {
    if (start == end) {
        // Leaf node
        tree[node].sum = tree[node].prefixSum = tree[node].suffixSum = tree[node].maxSum = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(tree, arr, start, mid, 2 * node);
    buildTree(tree, arr, mid + 1, end, 2 * node + 1);

    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

// Query the segment tree to get the maximum subarray sum in a given range
SegmentTreeNode queryTree(vector<SegmentTreeNode>& tree, int start, int end, int l, int r, int node) {
    // If the query range is outside the node range
    if (r < start || l > end) {
        SegmentTreeNode nullNode;
        nullNode.sum = nullNode.prefixSum = nullNode.suffixSum = nullNode.maxSum = INT_MIN;
        return nullNode;
    }

    // If the current segment is completely within the query range
    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    SegmentTreeNode left = queryTree(tree, start, mid, l, r, 2 * node);
    SegmentTreeNode right = queryTree(tree, mid + 1, end, l, r, 2 * node + 1);

    return merge(left, right);
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    int n = arr.size();

    // Build the segment tree
    vector<SegmentTreeNode> tree(4 * n);
    buildTree(tree, arr, 0, n - 1, 1);

    // Example query to get the maximum subarray sum in the range [0, n-1]
    SegmentTreeNode result = queryTree(tree, 0, n - 1, 0, n - 1, 1);
    cout << "Maximum subarray sum is " << result.maxSum << endl;

    return 0;
}
