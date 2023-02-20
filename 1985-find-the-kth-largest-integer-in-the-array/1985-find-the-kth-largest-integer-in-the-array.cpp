class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string& s1, const string& s2) {
            if(s1.size() != s2.size())
                return s1.size() < s2.size();
        else
            return s1 < s2;
        });
    
        return nums[nums.size() - k];
    }
};