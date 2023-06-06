class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(begin(nums), end(nums));
        long long res = 1, sz = nums.size(), cnt = 0;
        for(int i = 0; i < sz; ++i)
            if(res * nums[i] > 0 || (i + 1 < sz && nums[i + 1] < 0)) {
                res *= nums[i];
                ++cnt;
            }
    
        return cnt ? res : nums.back();
    }
};