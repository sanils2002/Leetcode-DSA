class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int mx = 0, sum = 0;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            sum += nums[idx];
            mx = max(mx, (sum + idx) / (idx + 1));
        }
        return mx;
    }
};