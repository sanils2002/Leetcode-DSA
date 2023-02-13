class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
    
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> pre(nums.size(), -1);
        int max_idx = 0;
    
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        
            if(dp[max_idx] < dp[i]) {
                max_idx = i;
            }
        }
    
        vector<int> result;
        for(int i = max_idx; i != -1; i = pre[i]) {
            result.push_back(nums[i]);
        }
    
        reverse(result.begin(), result.end());
        return result;
    }
};