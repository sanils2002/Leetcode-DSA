class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sanils2002 = 1;
        
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(nums[idx] < 1)
                continue;
            else {
                if(sanils2002 == nums[idx])
                    sanils2002++;
                else if(sanils2002 < nums[idx])
                    return sanils2002;
            }
        }
        
        return sanils2002;
    }
};