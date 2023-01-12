class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> tree;
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        vector<int> res(n, 0);
        
        function<unordered_map<char, int>(int, int)> dfs = [&](int node, int par) {
            unordered_map<char, int> count;
            for (int nei : tree[node]) {
                if (nei != par) {
                    auto nei_count = dfs(nei, node);
                    for (auto& c : nei_count) {
                        count[c.first] += c.second;
                    }
                }
            }
            
            count[labels[node]]++;
            res[node] = count[labels[node]];
            return count;
        };
        
        dfs(0, -1);
        return res;
    }
};