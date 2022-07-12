class Solution {
private:
    int Kadane(vector<int>& nums1, vector<int>& nums2) {
        int nSize = nums1.size(), nSum = 0, nMaxScore = 0;
        for(int idx = 0 ; idx < nSize ; ++idx) {
            nSum = max(nums2[idx] - nums1[idx], nSum + nums2[idx] - nums1[idx]);
            nMaxScore = max(nMaxScore, nSum);
        }
        return nMaxScore;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(accumulate(begin(nums1), end(nums1), 0) + Kadane(nums1, nums2), accumulate(begin(nums2), end(nums2), 0) + Kadane(nums2, nums1));
    }
};