class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int val = 1, temp = 0;
        for(auto &num : nums) {
            if(num == mx) {
                temp++, val = max(val, temp);
            }
            else
                temp = 0;
        }
        return val;
    }
};