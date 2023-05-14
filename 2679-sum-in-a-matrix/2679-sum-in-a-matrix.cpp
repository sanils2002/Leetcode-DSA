class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int score = 0;
        while(!nums.empty()) {
            int maxNum = INT_MIN;
            for(auto& row : nums) {
                int idx = max_element(row.begin(), row.end()) - row.begin();
                maxNum = max(maxNum, row[idx]);
                row.erase(row.begin() + idx);
            }
            score += maxNum;
            nums.erase(remove_if(nums.begin(), nums.end(), [](auto& row) { return row.empty(); }), nums.end());
        }
    
        return score;
    }
};