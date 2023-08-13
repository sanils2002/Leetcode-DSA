class Solution {
public:
    bool validPartition(vector<int>& nums) {
        bool dp[4] = {true, false, nums[0] == nums[1], false};
        for(int idx = 2 ; idx < nums.size() ; idx++) {
            bool two = nums[idx] == nums[idx - 1];
            bool three = (two && nums[idx] == nums[idx - 2]) || (nums[idx] - 1 == nums[idx - 1] && nums[idx] - 2 == nums[idx - 2]);
            dp[(idx + 1) % 4] = (dp[(idx - 1) % 4] && two) || (dp[(idx - 2) % 4] && three);
        }
        return dp[nums.size() % 4];
    }
};