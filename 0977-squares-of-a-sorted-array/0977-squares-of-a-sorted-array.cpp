class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &num : nums)
            num = pow(num, 2);
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};