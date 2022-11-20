class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int cnt = 0;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            for(int jdx = idx + 1 ; jdx < nums.size() ; jdx++) {
                for(int kdx = jdx + 1 ; kdx < nums.size() ; kdx++) {
                    if(nums[idx] != nums[jdx] and nums[jdx] != nums[kdx] and nums[idx] != nums[kdx])
                        cnt++;
                }
            }
        }
        return cnt;
    }
};