class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arrSize = nums.size();
        int arrSum = 0, maxSub = INT_MIN;
        for(int idx : nums) {
            arrSum = max(arrSum + idx, idx);
            maxSub = max(maxSub, arrSum);
        }
        return maxSub;
    }
};