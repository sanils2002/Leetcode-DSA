class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(lis.empty() || lis.back() < nums[idx])
                lis.push_back(nums[idx]);
            else {
                auto it = lower_bound(lis.begin(), lis.end(), nums[idx]);
                *it = nums[idx];
            }
        }
        return lis.size();
    }
};