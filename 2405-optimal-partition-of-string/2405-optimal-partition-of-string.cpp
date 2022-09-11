class Solution {
public:
    int partitionString(string s) {
        map<char, int> mp;
        
        int val = 0;
        for(int idx = 0 ; idx < s.size() ; idx++) {
            mp[s[idx]]++;
            
            if(mp[s[idx]] > 1) {
                mp.clear();
                val += 1;
                idx -= 1;
            }
        }
        
        return val + 1;
        
    }
};