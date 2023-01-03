class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        int curr = 1, lon_gest = 1;
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] != nums[i - 1]) {
                if(nums[i] == nums[i - 1] + 1)
                    curr++;
                else {
                    lon_gest = max(lon_gest, curr);
                    curr = 1;
                }
            }
        }
        
        return max(lon_gest, curr);
    }
};