class Solution {
private:
    int bfs(int i, std::unordered_map<int, std::vector<int>>& graph) {
        queue<int> queue;
        unordered_set<int> visited;
        queue.push(i);
        visited.insert(i);
        
        while(!queue.empty()) {
            int cur = queue.front();
            queue.pop();
            for(int neib : graph[cur]) {
                if(visited.find(neib) == visited.end()) {
                    visited.insert(neib);
                    queue.push(neib);
                }
            }
        }
    
        return visited.size();
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;
        int n = bombs.size();
        // Build the graph
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];

                // Create a path from node i to node j, if bomb i detonates bomb j.
                if((long)ri * ri >= (long)(xi - xj) * (xi - xj) + (long)(yi - yj) * (yi - yj)) {
                    graph[i].push_back(j);
                }
            }
        }

        int answer = 0;
        for(int i = 0; i < n; i++) {
            answer = max(answer, bfs(i, graph));
        }

        return answer;
    }
};