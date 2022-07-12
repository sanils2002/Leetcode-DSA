class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxima = *(max_element(nums.begin(), nums.end()));
        int minima = *(min_element(nums.begin(), nums.end()));
        
        vector<int> dp(maxima - minima + 1, 0);
        for(int idx = 0 ; idx < n ; idx++)
            dp[nums[idx] - minima] += nums[idx];
        
        n = maxima - minima + 1;
        if(n > 1)
            dp[1] = max(dp[0], dp[1]);
        for(int idx = 2 ; idx < n ; idx++)
            dp[idx] = max(dp[idx] + dp[idx-2], dp[idx-1]);
        
        return dp[n-1];
    }
};