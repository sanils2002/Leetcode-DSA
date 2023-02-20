class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int sumA = nums[n-1] - nums[0];
        int sumB = nums[n-1] - nums[2];
        int sumC = nums[n-3] - nums[0];
        int sumD = nums[n-2] - nums[1];
        
        return min(min(sumA, sumB), min(sumC, sumD));
    }
};