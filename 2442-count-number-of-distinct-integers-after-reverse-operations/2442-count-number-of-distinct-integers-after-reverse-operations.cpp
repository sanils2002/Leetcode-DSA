class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            s.insert(nums[idx]);
            int rev = 0;
            while(nums[idx]) {
                rev = rev * 10 + nums[idx] % 10;
                nums[idx] /= 10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};