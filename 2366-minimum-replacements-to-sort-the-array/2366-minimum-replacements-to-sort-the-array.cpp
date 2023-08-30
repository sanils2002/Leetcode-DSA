class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long repl = 0;
        int suf = nums[nums.size()-1];
        
        for(int idx = nums.size() - 2 ; idx >= 0 ; idx--) {
            long long temp = ceil(nums[idx] / (double)suf);
            
            repl += (temp - 1);
            temp = nums[idx] / temp;
            suf = temp;
        }
        
        return repl;
    }
};