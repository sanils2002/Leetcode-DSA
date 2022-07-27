class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int lastNonZeroFoundAt = 0, idx = 0 ; idx < nums.size() ; idx++) {
            if(0 != nums[idx])
                swap(nums[lastNonZeroFoundAt++], nums[idx]);
        }
    }
};