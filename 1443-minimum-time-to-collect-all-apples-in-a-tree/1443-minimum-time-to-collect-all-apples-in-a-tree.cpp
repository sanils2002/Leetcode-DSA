class Solution {
private:
    int dfs(int u, vector<int> adj[], vector<bool>& hasApple, vector<bool>& visited) {
        int ans = 0;
        visited[u] = true;
        for(int v : adj[u]) {
            if(!visited[v]) {
                int val = dfs(v, adj, hasApple, visited);
                if(val > 0 || hasApple[v]) 
                    ans += 2 + val;
            }
        }
        return ans;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        vector<bool> visited(n, false);
        return dfs(0, adj, hasApple, visited);
    }
};