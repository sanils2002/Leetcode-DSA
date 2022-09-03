class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(auto &num : nums) 
            mp[num]++;
        
        vector<int> res;
        for(auto &ip :mp)
            if(1 == ip.second)
                res.push_back(ip.first);
        
        return res;
    }
};