class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxima = *max_element(nums.begin(), nums.end());
        
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(maxima == nums[idx])
                return idx; 
        }
        
        return nums.size();
    }
};