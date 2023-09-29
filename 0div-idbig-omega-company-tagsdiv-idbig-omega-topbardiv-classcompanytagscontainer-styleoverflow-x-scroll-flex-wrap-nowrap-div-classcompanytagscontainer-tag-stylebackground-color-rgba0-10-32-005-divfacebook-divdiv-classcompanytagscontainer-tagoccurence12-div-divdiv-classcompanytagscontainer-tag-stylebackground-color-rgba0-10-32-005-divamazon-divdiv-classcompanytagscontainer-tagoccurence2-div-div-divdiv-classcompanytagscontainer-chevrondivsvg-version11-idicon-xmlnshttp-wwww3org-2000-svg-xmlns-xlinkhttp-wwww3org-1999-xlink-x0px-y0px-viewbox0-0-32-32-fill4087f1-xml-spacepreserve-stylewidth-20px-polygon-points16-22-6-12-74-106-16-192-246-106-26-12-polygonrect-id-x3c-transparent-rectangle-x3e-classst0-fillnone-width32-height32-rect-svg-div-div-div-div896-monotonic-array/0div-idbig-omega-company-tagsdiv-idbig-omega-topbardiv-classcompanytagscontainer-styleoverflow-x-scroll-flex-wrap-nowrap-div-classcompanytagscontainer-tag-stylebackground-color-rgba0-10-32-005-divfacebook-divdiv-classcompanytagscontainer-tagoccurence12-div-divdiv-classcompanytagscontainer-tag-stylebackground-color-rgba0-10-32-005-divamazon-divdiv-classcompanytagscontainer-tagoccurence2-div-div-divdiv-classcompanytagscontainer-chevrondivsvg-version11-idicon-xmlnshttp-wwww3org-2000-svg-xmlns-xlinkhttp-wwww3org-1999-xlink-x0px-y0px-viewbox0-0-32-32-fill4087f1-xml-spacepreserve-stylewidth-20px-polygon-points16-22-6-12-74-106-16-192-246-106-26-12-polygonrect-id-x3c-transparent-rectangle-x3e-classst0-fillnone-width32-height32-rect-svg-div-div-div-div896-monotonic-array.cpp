class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i - 1]) {
                decreasing = false;
            } 
            else if(nums[i] < nums[i - 1]) {
                increasing = false;
            }

            // If both increasing and decreasing flags are false, then the array is neither increasing nor decreasing.
            if(!increasing && !decreasing) {
                return false;
            }
        }

        return true;
    }
};