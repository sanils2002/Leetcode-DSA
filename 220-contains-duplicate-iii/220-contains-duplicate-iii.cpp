class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int, int>> vp;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            vp.push_back({nums[idx], idx});
        }
        
        sort(vp.begin(), vp.end());
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            for(int jdx = idx + 1 ; jdx < nums.size() ; jdx++) {
                if(abs(vp[idx].first + valueDiff >= vp[jdx].first)) {
                    if(abs(vp[idx].second - vp[jdx].second) <= indexDiff)
                        return true;
                }
                else
                    break;
            }
        }
        
        return false;
    }
};