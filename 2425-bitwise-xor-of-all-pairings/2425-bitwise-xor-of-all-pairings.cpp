class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int val = 0;
        if(nums2.size() % 2) {
            int idx = 0;
            while(idx < nums1.size())
                val ^= nums1[idx++];
        }
        if(nums1.size() % 2) {
            int idx = 0;
            while(idx < nums2.size())
                val ^= nums2[idx++];
        }
        return val;
    }
};

