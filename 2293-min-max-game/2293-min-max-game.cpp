class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int nSize = nums.size();
        if(1 == nSize)
            return nums[0];
        
        while(1 != nums.size()) {
            vector<int> v(nums.size()/2);
            for(int idx = 0 ; idx < nums.size()/2 ; idx++) {
                if(idx%2)
                    v[idx] = max(nums[2 * idx], nums[2 * idx + 1]);
                else 
                    v[idx] = min(nums[2 * idx], nums[2 * idx + 1]);
            }
            nums = v;
        }
        
        return nums[0];
    }
};