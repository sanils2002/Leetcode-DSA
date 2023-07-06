class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = numeric_limits<int>::max();
        vector<int> prefixSum(n + 1, 0);

        for(int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        for(int i = 0; i < n; ++i) {
            int left = i + 1;
            int right = n;
            int end = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(prefixSum[mid] - prefixSum[i] >= target) {
                    end = mid;
                    right = mid - 1;
                } 
                else {
                    left = mid + 1;
                }
            }

            if(end != -1) {
                minLength = min(minLength, end - i);
            }
        }

        return (minLength == numeric_limits<int>::max()) ? 0 : minLength;
    }
};