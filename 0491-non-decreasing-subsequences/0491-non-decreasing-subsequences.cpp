class Solution {
private:
    void dfs(set<vector<int>>& res, vector<int>& temp, int start, vector<int>& nums) {
        if(temp.size() >= 2) 
            res.insert(temp);
        for(int i = start; i < nums.size(); i++) {
            if(temp.empty() || nums[i] >= temp.back()) {
                temp.push_back(nums[i]);
                dfs(res, temp, i + 1, nums);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        dfs(res, temp, 0, nums);
        return vector<vector<int>> (res.begin(), res.end());
    }
};