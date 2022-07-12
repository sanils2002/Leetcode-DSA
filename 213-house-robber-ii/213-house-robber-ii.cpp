class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(1 == n) return nums[0];
        if(2 == n) return max(nums[0], nums[1]);
        
        vector<int> heist1(n), heist2(n);
        heist1[0] = nums[0]; heist1[1] = nums[0]; // 1 --> n-1
        heist2[0] = 0; heist2[1] = nums[1]; // 2 to n
        
        for(int idx = 2 ; idx < n ; idx++) {
            heist1[idx] = max(nums[idx] + heist1[idx-2], heist1[idx-1]);
            heist2[idx] = max(nums[idx] + heist2[idx-2], heist2[idx-1]);
        }
        
        return max(heist1[n-2], heist2[n-1]);
    }
};