class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int trgle = 0;
        
        for(int idx = nums.size() - 1 ; idx >= 0 ; idx--) {
            int st = 0, en = idx - 1;
            while(st < en) {
                if(nums[st] + nums[en] > nums[idx])
                    trgle += (en - st), en--;
                else
                    st++;
            }
        }
        
        return trgle;
    }
};