class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarray = 0, countZero = 0;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(0 == nums[idx]) {
                countZero++;
            }
            else {
                subarray += (countZero*(countZero+1)) / 2;
                countZero = 0;
            }
        }
        
        subarray += (countZero*(countZero+1)) / 2;
        
        return subarray;
    }
};