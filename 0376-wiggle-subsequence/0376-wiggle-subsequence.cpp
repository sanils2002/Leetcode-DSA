class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return n;

        int up = 1;    // Length of the longest wiggle subsequence ending with a positive difference
        int down = 1;  // Length of the longest wiggle subsequence ending with a negative difference

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1])
                up = down + 1;
            else if(nums[i] < nums[i - 1])
                down = up + 1;
        }

        return max(up, down);
    }
};