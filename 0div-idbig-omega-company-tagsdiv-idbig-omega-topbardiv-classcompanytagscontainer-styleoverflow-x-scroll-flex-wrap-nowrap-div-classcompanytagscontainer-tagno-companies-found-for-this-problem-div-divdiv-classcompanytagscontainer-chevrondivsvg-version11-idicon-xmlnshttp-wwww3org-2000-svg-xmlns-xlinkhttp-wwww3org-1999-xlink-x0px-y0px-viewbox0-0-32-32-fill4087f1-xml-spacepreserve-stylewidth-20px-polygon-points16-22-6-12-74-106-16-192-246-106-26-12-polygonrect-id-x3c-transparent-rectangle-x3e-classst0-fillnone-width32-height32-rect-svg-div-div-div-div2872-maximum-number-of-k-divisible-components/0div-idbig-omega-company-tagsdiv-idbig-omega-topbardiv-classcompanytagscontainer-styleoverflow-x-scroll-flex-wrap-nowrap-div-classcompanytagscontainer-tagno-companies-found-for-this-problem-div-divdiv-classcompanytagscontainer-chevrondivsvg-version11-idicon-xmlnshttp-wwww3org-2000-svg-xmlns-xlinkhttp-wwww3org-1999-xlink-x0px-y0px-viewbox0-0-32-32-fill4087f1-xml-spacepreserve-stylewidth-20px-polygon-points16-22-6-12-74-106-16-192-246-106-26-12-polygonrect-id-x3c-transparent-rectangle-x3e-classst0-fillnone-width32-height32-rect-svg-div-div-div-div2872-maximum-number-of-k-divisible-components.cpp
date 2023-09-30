class Solution {
private:
    int res;
    int dfs(int i, vector<vector<int>>& adj, vector<int>& values, int k, int t) {
        int val = 0;
        for(int j = 0 ; j < adj[i].size() ; j++) {
            if(t == adj[i][j])
                continue;
            val += dfs(adj[i][j], adj, values, k, i);
        }
        
        val += values[i];
        if(val % k == 0) {
            res++;
            return 0;
        }
        return val;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        res = 0;
        dfs(0, adj, values, k, -1);
        
        return res;
    }
};

