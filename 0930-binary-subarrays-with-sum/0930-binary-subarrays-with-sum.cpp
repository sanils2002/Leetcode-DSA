class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
    int left = 0, right = 0, sum = 0, count = 0;
    
    while (right < n) {
        sum += nums[right];
        
        while (left < right && sum > goal) {
            sum -= nums[left];
            left++;
        }
        
        if (sum == goal) {
            int l = left;
            while (l < right && nums[l] == 0) {
                l++;
            }
            count += l - left + 1;
        }
        
        right++;
    }
    
    return count;
    }
};