class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(j < 1e5) {
            sum += nums[j % n];
            while(sum > target){
                sum -= nums[i % n];
                i++;
            }
            
            if(sum == target){
                ans = min(ans, (j - i) + 1);
            }
            
            j++;
        }
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;
    }
};