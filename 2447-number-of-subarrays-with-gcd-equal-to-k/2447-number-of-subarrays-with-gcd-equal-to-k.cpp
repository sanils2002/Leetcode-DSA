class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        for(int idx = 0 ; idx < n ; idx++) {
            int curr = 0;
            for(int jdx = idx ; jdx < n ; jdx++) {
                curr = __gcd(curr, nums[jdx]);
                cnt += (k == curr) ? 1 : 0;
            }
        }
        return cnt;
    }
};