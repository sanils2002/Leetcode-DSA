class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int count = 0, divisor = 0;
        for(int i = 0; i < divisors.size(); i++) {
            int div_count = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] % divisors[i] == 0) 
                    div_count++;
            }
            if(count == div_count) {
                divisor = divisor == 0 ? divisors[i] : min(divisor, divisors[i]);
            }
            else if(div_count > count) {
                count = div_count;
                divisor = divisors[i];
            }
        }
        return divisor;
    }
};