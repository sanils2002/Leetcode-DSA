class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        int left = 0, right = 0;
        int countZeros = 0;

        while(right < n) {
            if(nums[right] == 0)
                countZeros++;

            while(countZeros > 1) {
                if(nums[left] == 0)
                    countZeros--;
                left++;
            }

            maxLength = max(maxLength, right - left);
            right++;
        }

        return maxLength;
    }
};