class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for(auto &num :nums)
            sum += num;
        
        int dig_sum = 0;
        for(auto &num : nums) {
            while(num > 0) {
                int x = num % 10;
                dig_sum += x;
                num /= 10;
            }
        }
        
        return abs(dig_sum - sum);
    }
};