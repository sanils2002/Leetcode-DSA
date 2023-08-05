class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> d;
        for (int i = 0; i < nums.size(); i++) {
            d[nums[i]].push_back(i);
        }
        
        int n = nums.size();
        int mx = n;
        
        for (const auto& entry : d) {
            const vector<int>& j = entry.second;
            int tot = 0;
            for (int k = 1; k < j.size(); k++) {
                tot = max(tot, ((j[k] - j[k - 1]) / 2));
            }
            tot = max(tot, (j[0] + n - j.back()) / 2);
            mx = min(mx, tot);
        }
        
        return mx;
    }
};