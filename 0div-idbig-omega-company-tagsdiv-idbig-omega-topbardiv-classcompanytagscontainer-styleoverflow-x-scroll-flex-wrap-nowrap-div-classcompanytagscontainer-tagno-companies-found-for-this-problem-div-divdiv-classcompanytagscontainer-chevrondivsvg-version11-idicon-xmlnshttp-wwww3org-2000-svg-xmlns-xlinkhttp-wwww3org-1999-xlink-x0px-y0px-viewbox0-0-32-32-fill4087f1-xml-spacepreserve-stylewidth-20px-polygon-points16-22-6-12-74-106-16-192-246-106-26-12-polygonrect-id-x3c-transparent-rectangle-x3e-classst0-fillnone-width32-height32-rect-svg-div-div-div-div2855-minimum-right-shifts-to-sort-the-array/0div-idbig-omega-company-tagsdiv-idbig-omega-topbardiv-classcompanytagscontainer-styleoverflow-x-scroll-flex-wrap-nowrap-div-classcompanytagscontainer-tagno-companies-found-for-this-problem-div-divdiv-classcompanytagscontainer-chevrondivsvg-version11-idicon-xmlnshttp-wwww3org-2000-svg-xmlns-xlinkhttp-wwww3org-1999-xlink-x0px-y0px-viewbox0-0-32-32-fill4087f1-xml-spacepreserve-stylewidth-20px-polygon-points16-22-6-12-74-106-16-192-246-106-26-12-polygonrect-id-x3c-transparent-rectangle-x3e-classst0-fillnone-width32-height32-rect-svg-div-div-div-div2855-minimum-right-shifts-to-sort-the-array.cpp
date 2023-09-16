class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(nums);
        sort(v.begin(), v.end());
        
        for(int i = 0 ; i < n ; i++) {
            if(nums == v)
                return i;
            rotate(nums.rbegin(), nums.rbegin() + 1, nums.rend());
        }
        
        return -1;
    }
};