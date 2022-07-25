class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> mp;
        for(auto &times : time)
            mp[times%60]++;
        
        long long int val = 0;
        for(auto &times : time) {
            if(0 == times%60 or 30 == times%60)
                val--;
            if(0 == times%60)
                val += mp[0];
            else
                val += mp[60-(times%60)];
        }
        
        return val/2;
    }
};