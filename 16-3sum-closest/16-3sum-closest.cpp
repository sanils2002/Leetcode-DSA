class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nSize = nums.size(), CloDiff = INT_MAX, clo_tar = 0, sum = 0;
        
        sort(nums.begin(), nums.end());
        for(int idx = 0 ; idx < nSize - 2 ; idx++) {
            int l = idx + 1, r = nSize - 1;
            while(l < r) {
                sum = nums[idx] + nums[l] + nums[r];
                int curDiff  = max(sum, target) - min(sum, target);
                if(curDiff < CloDiff)
                    CloDiff = curDiff, clo_tar = sum;
                if(sum < target)
                    l++;
                else
                    r--;
            }
        }
        
        return clo_tar;
    }
};