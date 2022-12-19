class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj_list[n];
        if(source == destination)
            return true;
        
        for(auto &edge : edges) {
            adj_list[edge[1]].push_back(edge[0]);
            adj_list[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> vis(n, false);
        vis[source] = true;
        queue<int> bFS;
        bFS.push(source);
        
        while(!bFS.empty()) {
            int curr = bFS.front();
            bFS.pop();
            if(destination == curr)
                return true;
            
            for(auto &next : adj_list[curr]) {
                if(!vis[next]) {
                    vis[next] = true;
                    bFS.push(next);
                }
            }
        }
        
        return false;
    }
};