// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         // Step 1: Build adjacency list and indegree array
//         vector<vector<int>> adj(numCourses);
//         vector<int> indegree(numCourses, 0);

//         for (auto &p : prerequisites) {
//             int course = p[0];
//             int prereq = p[1];
//             adj[prereq].push_back(course);
//             indegree[course]++;
//         }

//         // Step 2: Push all nodes with indegree 0 into queue
//         queue<int> q;
//         for (int i = 0; i < numCourses; i++) {
//             if (indegree[i] == 0) q.push(i);
//         }

//         // Step 3: Process nodes in BFS manner
//         int count = 0;
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             count++;

//             for (int neighbor : adj[node]) {
//                 indegree[neighbor]--;
//                 if (indegree[neighbor] == 0) {
//                     q.push(neighbor);
//                 }
//             }
//         }

//         // Step 4: If we processed all courses, return true
//         return count == numCourses;
//     }
// };



class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        int V = numCourses;

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);

        for (auto& p : prerequisites) {
            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);
        }

        // Step 2: Calculate indegree
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Step 3: Push indegree-zero nodes
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Apply Kahn's BFS
        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 5: Check if all courses can be completed
        return count == V;
    }
};
