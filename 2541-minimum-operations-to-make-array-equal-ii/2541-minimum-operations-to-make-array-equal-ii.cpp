class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<long long> DIFF(nums1.size());
        if(nums1 == nums2) {
            return 0;
        }
        for(long long i = 0; i < nums1.size(); i++) {
            DIFF[i] = nums1[i] - nums2[i];
        }

        if(accumulate(DIFF.begin(), DIFF.end(), 0) != 0) {
            return -1;
        }
        
        long long res = 0;
        for(long long i : DIFF) {
            if(i > 0) {
                res += i;
            }
        }

        if(k != 0 && res % k == 0) {
            return res / k;
        } 
        else {
            return -1;
        }
    }
};