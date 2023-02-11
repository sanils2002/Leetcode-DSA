class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> G[105];
        vector<int> res(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2));
        queue<vector<int>> q;
        
        for(auto& r: redEdges)
            G[r[0]].push_back({r[1], 0});
        for(auto& b: blueEdges)
            G[b[0]].push_back({b[1], 1});
        
        q.push({0, 0, -1});
        vis[0][0] = vis[0][1] = true;
        res[0] = 0; 
        
        while(!q.empty()) {
            vector<int> temp = q.front();
            q.pop();
            int u = temp[0], lvl = temp[1], col = temp[2];
            for(auto& V : G[u]) {
                int v = V[0], ncol = V[1];
                if(vis[v][ncol] || ncol == col)
                    continue;
                vis[v][ncol] = true;
                q.push({v, lvl + 1, ncol});
                if(res[v] == -1)
                    res[v] = lvl + 1;
            }
        }
        return res;
    }
};