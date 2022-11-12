class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (auto idx = m ; idx < m + n ; idx++) {
            nums1[idx] = nums2[idx - m];
        }
        sort(nums1.begin(), nums1.end());
    }
};