class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        if(nums[0] == 1 and nums[nums.size() - 1] == nums.size())
            return 0;
        
        int idx = 0, x = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == 1)
                idx = i;
            else {
                if(nums[i] == nums.size())
                    x = i;
            }
        }
        
        if(x > idx)
            return idx + nums.size() - 1 - x;
        else
            return idx + nums.size() - 1 - x - 1;
        
    }
};