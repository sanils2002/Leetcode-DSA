class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto pivot = lower_bound(nums.begin(), nums.end(), target);
        auto joint = upper_bound(nums.begin(), nums.end(), target);
        
        if(!binary_search(nums.begin(), nums.end(), target))
            return {-1, -1};
        
        int start = pivot - nums.begin();
        int end = joint - nums.begin() - 1;
        
        return {start, end};
    }
};