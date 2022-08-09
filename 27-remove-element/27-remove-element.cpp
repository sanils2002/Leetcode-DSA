class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (int jdx = 0; jdx < nums.size() ; jdx++) {
            if (val != nums[jdx]) {
                nums[idx] = nums[jdx];
                idx++;
            }
        }
        return idx;
    }
};