
class Solution {
public:
    vector<vector<int>> tree, newTree;
    vector<int> newParent, ans, lastSeen;

    // DFS 1: Find the nearest ancestor with the same character
    void dfs1(int node, string &s) {

        int idx = s[node] - 'a';

        // Store previous occurrence of this character
        int previous = lastSeen[idx];

        // Update parent if a matching ancestor exists
        if (previous != -1) {
            newParent[node] = previous;
        }

        // Mark current node as latest occurrence
        lastSeen[idx] = node;

        // Traverse children in original tree
        for (int child : tree[node]) {
            dfs1(child, s);
        }

        // Backtrack and restore previous occurrence
        lastSeen[idx] = previous;
    }

    // DFS 2: Calculate subtree sizes
    int dfs2(int node) {

        int size = 1;

        for (int child : newTree[node]) {
            size += dfs2(child);
        }

        ans[node] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        tree.resize(n);
        newTree.resize(n);

        newParent = parent;
        ans.resize(n, 0);
        lastSeen.assign(26, -1);

        // Step 1: Build original tree
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        // Step 2: Find updated parents
        dfs1(0, s);

        // Step 3: Build modified tree
        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        // Step 4: Calculate subtree sizes
        dfs2(0);

        return ans;
    }
};
