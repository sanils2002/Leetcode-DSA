class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // sort the array in ascending order
        int n = nums.size();
        int j = 0; // left pointer
        long long sum = 0; // sum of the elements in the current window
        int res = 1; // current max frequency
        for (int i = 0; i < n; i++) { // right pointer
            sum += nums[i];
            while ((long long)(i-j+1)*nums[i]-sum > k) { // move the left pointer if the sum exceeds k
                sum -= nums[j];
                j++;
            }
            res = max(res, i-j+1); // update the max frequency
        }
        return res;
    }
};