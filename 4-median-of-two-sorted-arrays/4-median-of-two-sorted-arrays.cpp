class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0.0;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        if(0 == nums1.size() % 2)
            median = ( (nums1[nums1.size()/2] + nums1[nums1.size()/2 - 1]) ) / 2.0;
        else 
            median = nums1[floor(nums1.size()/2)];
        
        return median;
    }
};