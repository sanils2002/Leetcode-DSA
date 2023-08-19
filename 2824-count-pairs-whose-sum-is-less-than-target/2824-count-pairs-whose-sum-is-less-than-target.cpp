class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;

        while(left < right) {
            if(nums[left] + nums[right] < target) {
                // Since the array is sorted, all values between left and right
                // will also satisfy the condition. So, increment the count.
                count += right - left;
                left++;
            } 
            else {
                right--;
            }
        }

        return count;
    }
};