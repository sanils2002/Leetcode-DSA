class Solution {
private:
    int countExpressions(vector<int>& nums, int target, int idx, int curr_sum) {
        if(idx == nums.size()) {
            if(curr_sum == target) {
                return 1;
            }
            return 0;
        }
    
        int count = 0;
        count += countExpressions(nums, target, idx + 1, curr_sum + nums[idx]);
        count += countExpressions(nums, target, idx + 1, curr_sum - nums[idx]);
    
        return count;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countExpressions(nums, target, 0, 0);
    }
};