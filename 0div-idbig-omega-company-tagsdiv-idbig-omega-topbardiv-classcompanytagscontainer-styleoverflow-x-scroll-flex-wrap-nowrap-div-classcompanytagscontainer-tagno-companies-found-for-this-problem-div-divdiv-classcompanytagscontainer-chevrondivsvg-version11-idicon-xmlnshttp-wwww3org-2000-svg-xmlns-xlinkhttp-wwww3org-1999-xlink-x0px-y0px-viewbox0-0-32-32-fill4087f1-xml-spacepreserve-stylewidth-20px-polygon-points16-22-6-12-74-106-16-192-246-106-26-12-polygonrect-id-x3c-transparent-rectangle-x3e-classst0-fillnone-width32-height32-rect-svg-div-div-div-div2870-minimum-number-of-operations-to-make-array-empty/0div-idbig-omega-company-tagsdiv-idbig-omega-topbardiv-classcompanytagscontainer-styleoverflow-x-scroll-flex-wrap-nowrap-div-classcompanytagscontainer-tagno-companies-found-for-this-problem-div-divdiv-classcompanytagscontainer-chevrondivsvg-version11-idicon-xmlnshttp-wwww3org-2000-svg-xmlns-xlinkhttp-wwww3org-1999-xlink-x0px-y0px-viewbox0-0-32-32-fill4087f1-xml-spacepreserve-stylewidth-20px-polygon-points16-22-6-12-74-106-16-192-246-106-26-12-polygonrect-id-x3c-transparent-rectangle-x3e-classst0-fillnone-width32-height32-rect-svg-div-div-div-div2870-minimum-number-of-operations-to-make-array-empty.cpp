class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for(auto num : nums)
            mp[num]++;
        
        int val = 0;
        for(auto ip : mp) {
            if(ip.second < 2)
                return -1;
            val += ((ip.second + 2) / 3);
        }
        
        return val;
    }
};