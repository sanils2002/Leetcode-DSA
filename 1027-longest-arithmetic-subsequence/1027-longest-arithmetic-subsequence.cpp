class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
    
        // Create a vector of unordered maps to store the lengths of arithmetic subsequences
        vector<unordered_map<int, int>> dp(n);
    
        // Iterate over each element in the array
        for(int i = 0; i < n; i++) {
            // Iterate over all previous elements to find the maximum length subsequence
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
            
                // Retrieve the length of the subsequence ending at nums[j] with the given difference
                int length = dp[j].count(diff) ? dp[j][diff] : 1;
            
                // Update the length of the subsequence ending at nums[i] with the given difference
                dp[i][diff] = max(dp[i][diff], length + 1);
            
                // Update the maximum length if necessary
                maxLength = max(maxLength, dp[i][diff]);
            }
        }
    
        return maxLength;
    }
};