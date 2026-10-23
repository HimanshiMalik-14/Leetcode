// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
//         if (state[node] != 0) return state[node] == 2; // already visited
//         state[node] = 1; // mark as visiting

//         for (int nei : graph[node]) {
//             if (!dfs(nei, graph, state)) return false; // leads to cycle
//         }

//         state[node] = 2; // mark as safe
//         return true;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> state(n, 0); // 0=unvisited, 1=visiting, 2=safe
//         vector<int> result;

//         for (int i = 0; i < n; i++) {
//             if (dfs(i, graph, state)) result.push_back(i);
//         }

//         return result;
//     }
// };


// class Solution {
// private:
//     bool dfs(int node, vector<vector<int>>& graph,
//              vector<int>& vis, vector<int>& pathVis,
//              vector<int>& check) {

//         vis[node] = 1;
//         pathVis[node] = 1;
//         check[node] = 0;  // Initially assume unsafe

//         for (auto neighbor : graph[node]) {

//             if (!vis[neighbor]) {
//                 if (dfs(neighbor, graph, vis, pathVis, check)) {
//                     return true;
//                 }
//             }
//             else if (pathVis[neighbor]) {
//                 return true;  // Cycle found
//             }
//         }

//         pathVis[node] = 0;
//         check[node] = 1;  // No cycle reachable: safe
//         return false;
//     }

// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();

//         vector<int> vis(n, 0);
//         vector<int> pathVis(n, 0);
//         vector<int> check(n, 0);

//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 dfs(i, graph, vis, pathVis, check);
//             }
//         }

//         vector<int> safeNodes;

//         for (int i = 0; i < n; i++) {
//             if (check[i] == 1) {
//                 safeNodes.push_back(i);
//             }
//         }

//         return safeNodes;
//     }
// };

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adjRev(V);
        vector<int> outdegree(V, 0);

        // Build reverse graph
        for (int i = 0; i < V; i++) {
            outdegree[i] = graph[i].size();

            for (auto neighbor : graph[i]) {
                adjRev[neighbor].push_back(i);
            }
        }

        queue<int> q;

        // Push terminal nodes into queue
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;

        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for (auto neighbor : adjRev[node]) {
                outdegree[neighbor]--;

                if (outdegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};