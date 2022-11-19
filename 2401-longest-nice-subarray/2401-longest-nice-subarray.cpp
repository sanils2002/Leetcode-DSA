class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0, fast = 0, slow = 0, mx = 0;
        while(fast < nums.size()) {
            while(0 != (mask & nums[fast]))
                mask ^= nums[slow], slow++;
            mask |= nums[fast];
            mx = max(mx, fast - slow + 1);
            fast++;
        }
        return mx;
    }
};