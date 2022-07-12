class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int sanils23 = nums[0]; // Maxima
        int sanils2002 = nums[0]; // Minima
        int leetcode = nums[0]; // Answer
        
        for(int idx = 1 ; idx < n ; idx++) {
            if(nums[idx] < 0) swap(sanils23, sanils2002);
            
            sanils23 = max(nums[idx], sanils23*nums[idx]);
            sanils2002 = min(nums[idx], sanils2002*nums[idx]);
            
            leetcode = max(leetcode, sanils23);
        }
        return leetcode;
    }
};