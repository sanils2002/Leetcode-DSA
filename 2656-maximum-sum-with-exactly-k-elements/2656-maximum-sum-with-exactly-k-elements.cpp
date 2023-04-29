class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        int m = 0;
        while(k > 0) {
            m += nums[0];
            nums[0]++;
            k--;
        }
        
        return m;
    }
};