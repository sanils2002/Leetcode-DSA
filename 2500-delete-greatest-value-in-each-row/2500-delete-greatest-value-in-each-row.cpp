class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;
        
        while(!grid.empty()) {
            vector<int> mx;
            
            for(auto &r : grid) {
                mx.push_back(*max_element(r.begin(), r.end()));
            }
            
            res += *max_element(mx.begin(), mx.end());
            
            for(auto &r : grid) {
                r.erase(max_element(r.begin(), r.end()));
            }
            
            grid.erase(remove_if(grid.begin(), grid.end(), [](auto r) { return r.empty(); }), grid.end());
        }
        
        return res;
    }
};