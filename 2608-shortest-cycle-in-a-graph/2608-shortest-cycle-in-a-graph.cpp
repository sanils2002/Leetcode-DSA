class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // Create an adjacency list to represent the graph
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int shortest = INT_MAX;

        // For each vertex, find the shortest cycle that includes it
        for(int i = 0; i < n; i++) {
            // Initialize distance and parent arrays
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            // Add the current vertex to the queue and set its distance to 0
            q.push(i);
            dist[i] = 0;

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : adj[u]) {
                    if(v == parent[u]) {
                        continue; // Skip the parent node
                    }
                    if(dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } 
                    else if(parent[u] != v) {
                        shortest = min(shortest, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (shortest == INT_MAX) ? -1 : shortest;
    }
};