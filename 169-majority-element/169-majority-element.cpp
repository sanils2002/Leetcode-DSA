class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int idx = 0 ; idx < nums.size() ; idx++)
            m[nums[idx]]++;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(m[nums[idx]] > nums.size() / 2)
                return nums[idx];
        }
        
        return nums.back();
        
    }
};