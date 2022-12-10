class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size(), ans = INT_MIN;
        
        vector<vector<int>> nodes(n);
        
        for(int i = 0 ; i < edges.size() ; i++) {
            if(vals[edges[i][1]] > 0) 
                nodes[edges[i][0]].push_back(vals[edges[i][1]]);
            if(vals[edges[i][0]] > 0) 
                nodes[edges[i][1]].push_back(vals[edges[i][0]]);
        }
        
        for(int i = 0 ; i < n ; i++) {
            sort(nodes[i].rbegin(), nodes[i].rend());
            
            int t = vals[i];
            for(int j = 0; j < min(k, (int)nodes[i].size()); j++) 
                t += nodes[i][j];
            ans = max(ans, t);
        }
        
        return ans;
    }
};