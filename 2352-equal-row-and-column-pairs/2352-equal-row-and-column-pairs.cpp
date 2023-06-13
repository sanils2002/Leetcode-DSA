class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        for(auto &ip : grid)
            mp[ip]++;
        
        int pairs = 0;
        for(int idx = 0 ; idx < grid[0].size() ; idx++) {
            vector<int> temp;
            for(int jdx = 0 ; jdx < grid.size() ; jdx++) {
                temp.push_back(grid[jdx][idx]);
            }
            pairs += mp[temp];
        }
        
        return pairs;
    }
};