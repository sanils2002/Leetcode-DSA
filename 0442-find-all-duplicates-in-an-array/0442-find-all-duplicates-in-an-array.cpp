class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(auto &num : nums)
            mp[num]++;
        
        vector<int> v;
        for(auto &ip : mp) {
            if(ip.second > 1)
                v.push_back(ip.first);
        }
        
        return v;
    }
};