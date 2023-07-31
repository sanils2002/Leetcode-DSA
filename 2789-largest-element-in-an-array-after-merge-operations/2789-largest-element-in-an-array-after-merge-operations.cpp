class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size(), i = n - 1;
        long ans = 0, sum = nums[i];
        while(i > 0) {
            if(sum >= nums[i - 1])
                sum += nums[i - 1];
            else
                sum = nums[i - 1];
            i--;
        }
        
        ans = max(ans,sum);
        return ans;
    }
};