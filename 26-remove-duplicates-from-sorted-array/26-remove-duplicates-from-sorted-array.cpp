class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(0 == nums.size())
            return 0;
        
        int idx = 0;
        
        for(int jdx = 1 ; jdx < nums.size() ; jdx++) {
            if(nums[idx] != nums[jdx]) {
                idx++;
                nums[idx] = nums[jdx];
            }
        }
        
        return idx + 1;
    }
};