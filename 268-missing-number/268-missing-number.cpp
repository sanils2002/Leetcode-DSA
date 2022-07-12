class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(idx != nums[idx])
                return idx;
        }
        return nums.size();
    }
};