class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(auto idx = 0 ; idx < nums.size() - 1 ; idx++) {
            if(nums[idx] == nums[idx + 1]) {
                nums[idx] *= 2;
                nums[idx + 1] = 0;
            }
        }
        auto i = 0;
        for (auto jdx = 0; jdx < nums.size(); jdx++)
            if (0 != nums[jdx]) 
                nums[i++] = nums[jdx];
        while (i < nums.size()) 
            nums[i++] = 0;
        return nums;
    }
};