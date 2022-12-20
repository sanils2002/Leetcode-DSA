class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        // Create a vector of sets to represent the graph
        vector<unordered_set<int>> G(n + 1);
        // Add the edges to the graph
        for(auto &edge : edges) {
            G[edge[0]].insert(edge[1]);
            G[edge[1]].insert(edge[0]);
        }

        // Create a vector to store the nodes with odd degree
        vector<int> odd;
        for(int i = 1; i <= n; i++) {
            if(G[i].size() % 2 == 1) {
                odd.push_back(i);
            }
        }

        // Check if there are 2 or 4 nodes with odd degree
        if(odd.size() == 2) {
            // Check if there is a node that is not connected to both odd-degree nodes
            int a = odd[0], b = odd[1];
            for(int i = 1; i <= n; i++) {
                if (G[a].count(i) == 0 && G[b].count(i) == 0) {
                    return true;
                }
            }
            return false;
        }
    
        if(odd.size() == 4) {
            // Check if there is a pair of nodes that are not connected to each other
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            return  (G[a].count(b) == 0 && G[c].count(d) == 0) || 
                (G[a].count(c) == 0 && G[b].count(d) == 0) ||
                (G[a].count(d) == 0 && G[c].count(b) == 0);
        }
        
        return odd.size() == 0;
    }
};