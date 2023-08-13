class Solution {
private:
    int maxDigit(int num) {
        int max_digit = 0;
        while(num > 0) {
            int digit = num % 10;
            max_digit = max(max_digit, digit);
            num /= 10;
        }
    
        return max_digit;
}
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = -1;

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(maxDigit(nums[i]) == maxDigit(nums[j])) {
                    max_sum = max(max_sum, nums[i] + nums[j]);
                }
            }
        }

        return max_sum;
    }
};