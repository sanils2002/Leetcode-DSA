class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> val;
        for(int idx = 0 ; idx < nums1.size() ; idx++) {
            int check = nums1[idx];
            for(int jdx = 0 ; jdx < nums2.size() ; jdx++) {
                if(check == nums2[jdx]) {
                     val.push_back(check);
                    //nums2[jdx] -= 1786;
                    //break;
                }
            }
        }
        
        set<int> s(val.begin(), val.end());
        val.assign(s.begin(), s.end());
        
        return val;
    }
};