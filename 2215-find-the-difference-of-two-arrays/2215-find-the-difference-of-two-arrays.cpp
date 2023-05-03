class Solution {
private:
    vector<int> helper(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for(int num : nums2)
            s2.insert(num);
        
        for(int num : nums1) {
            if(s2.find(num) == s2.end())
                s1.insert(num);
        }
        
        return vector<int> (s1.begin(), s1.end());
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {helper(nums1, nums2), helper(nums2, nums1)};
    }
};