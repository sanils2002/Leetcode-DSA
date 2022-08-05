class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1);
        dp[0] = 1;
        for(int idx = 1 ; idx <= target ; idx++) {
            for(auto &num : nums) {
                if(num <= idx)
                    dp[idx] += dp[idx - num];
            }
        }
        
        return dp[target];
    }
};