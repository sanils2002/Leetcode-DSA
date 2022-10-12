class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int idx = nums.size() - 3 ; idx >= 0 ; idx--) {
            if(nums[idx] + nums[idx + 1] > nums[idx + 2])
                return nums[idx] + nums[idx + 1] + nums[idx + 2];
        }
        return 0;
    }
};