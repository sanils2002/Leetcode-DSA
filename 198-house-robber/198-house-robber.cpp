class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int heist1 = nums[0];
        int heist2 = 0;
        
        int sanils2002;
        
        for(int idx = 1 ; idx < n ; idx++) {
            sanils2002 = max(heist1, heist2);
            heist1 = heist2 + nums[idx];
            heist2 = sanils2002;
        }

        return max(heist1, heist2);
    }
};