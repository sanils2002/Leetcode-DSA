class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // Merge nums1 and nums2 into a single vector
        vector<vector<int>> merged(nums1);
        merged.insert(merged.end(), nums2.begin(), nums2.end());
    
        // Sort the merged vector by id
        sort(merged.begin(), merged.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
    
        // Merge values for ids that appear in both arrays
        vector<vector<int>> result;
        int i = 0, j = 1;
        while(i < merged.size()) {
            while(j < merged.size() && merged[j][0] == merged[i][0]) {
                merged[i][1] += merged[j][1];
                j++;
            }
            result.push_back(merged[i]);
            i = j;
            j++;
        }
    
        return result;
    }
};