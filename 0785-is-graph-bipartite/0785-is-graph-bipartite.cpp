class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for(int v : graph[u]) {
                        if(color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } 
                        else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    
        return true;
    }
};

//This function uses a breadth-first search (BFS) algorithm to check whether the graph is bipartite. It starts by assigning each node a color of either 0 or 1. Then, it checks if there is a conflict between the color of the current node and the color of its adjacent nodes. If there is, it means the graph is not bipartite and the function returns false. If the function completes the BFS and there are no conflicts, it means the graph is bipartite and the function returns true.