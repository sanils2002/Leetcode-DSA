class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2)
            return -1;
        sort(nums.begin(), nums.end());
        int x = nums[0];
        for(int i = 1 ; i <= nums.size()-2 ; i++) {
            x = max(x, nums[i]);
        }
        
        return x;
    }
};