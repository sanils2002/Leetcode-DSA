class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(int idx = 0 ; idx < nums.size() ; idx++)
            mp[nums[idx]]++;
        
        for(auto &ip : mp) {
            if(1 == ip.second)
                return ip.first;
        }
        
        return -1;
    }
};