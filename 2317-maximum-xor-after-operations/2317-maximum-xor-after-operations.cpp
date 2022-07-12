class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int sanXOR = 0;
        for(int idx = 0 ; idx < nums.size() ; idx++)
            sanXOR |= nums[idx];
        return sanXOR;
    }
};