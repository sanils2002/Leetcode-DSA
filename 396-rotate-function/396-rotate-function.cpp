class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int numSum = 0, numRot = 0;
        int numSize = nums.size();
        for(int idx = 0 ; idx < numSize ; idx++) {
            numSum += nums[idx];
            numRot += idx * nums[idx];
        }
        int maxF= numRot;
        for(int idx = numSize - 1 ; idx >= 0 ; idx--) {
            int tempRot = numRot - (numSize - 1) * nums[idx] + numSum - nums[idx];
            maxF = max(maxF, tempRot);
            numRot = tempRot;
        }
        return maxF;
    }
};