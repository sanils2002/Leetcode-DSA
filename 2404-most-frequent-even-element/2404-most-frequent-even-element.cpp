class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for(auto &num: nums)
            mp[num]++;
        
        int cnt = -1, val = -1;
        for(auto &ip : mp)
            if(ip.second > cnt and 0 == ip.first%2) {
                cnt = ip.second;
                val = ip.first;
            }
        
        return val;
    }
};