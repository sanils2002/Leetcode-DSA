class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i1 = 0, i2 = n - 1;
        vector<int> ans(n);
        
        for(int idx = 0 ; idx < n ; ++idx) {
            if(0 == nums[idx] % 2)
                ans[i1++] = nums[idx];
            else 
                ans[i2--] = nums[idx];
        }
        return ans;
    }
};