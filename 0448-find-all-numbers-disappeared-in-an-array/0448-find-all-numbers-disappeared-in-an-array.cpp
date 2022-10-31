class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> check(nums.size() + 1, false);
        vector<int> v;
        
        for(auto &num : nums)
            check[num] = true;
        for(auto idx = 1 ; idx <= nums.size() ; idx++) {
            if(!check[idx])
                v.push_back(idx);
        }
        return v;
    }
};