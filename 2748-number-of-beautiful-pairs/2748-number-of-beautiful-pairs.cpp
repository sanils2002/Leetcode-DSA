class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            string numStr = to_string(nums[i]);
            int firstDigit = numStr[0] - '0';
            int lastDigit = numStr[numStr.length() - 1] - '0';

            for(int j = i + 1; j < n; j++) {
                string nextNumStr = to_string(nums[j]);
                int nextFirstDigit = nextNumStr[0] - '0';
                int nextLastDigit = nextNumStr[nextNumStr.length() - 1] - '0';

                if(__gcd(firstDigit, nextLastDigit) == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};