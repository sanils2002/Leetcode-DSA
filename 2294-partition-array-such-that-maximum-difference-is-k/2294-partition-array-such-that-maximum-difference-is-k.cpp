class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int sanils2002 = 0, lo = 0, hi = 1;
        sort(nums.begin(), nums.end());
        
        while(hi < nums.size()) {
            if(nums[hi] - nums[lo] > k) {
                sanils2002 += 1;
                lo = hi;
                hi += 1;
            }
            else {
                hi += 1;
            }
        }
        
        return sanils2002 + 1;
    }
};