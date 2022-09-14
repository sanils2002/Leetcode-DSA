class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        vector<int> val;
        
        for(int idx = 0 ; idx < nums1.size() ; idx++) {
            mp[nums1[idx]]++;
        }
        for(int jdx = 0 ; jdx < nums2.size() ; jdx++) {
            if(mp[nums2[jdx]]) {
                val.push_back(nums2[jdx]);
                mp[nums2[jdx]]--;
            }
        }
        
        return val;
    }
};