class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj_list(n), ans;
        for(auto &edge : edges)
            adj_list[edge[1]]++;
        
        for(int idx = 0 ; idx < n ; idx++) {
            if(!adj_list[idx])
                ans.push_back(idx);
        }
        
        return ans;
    }
};