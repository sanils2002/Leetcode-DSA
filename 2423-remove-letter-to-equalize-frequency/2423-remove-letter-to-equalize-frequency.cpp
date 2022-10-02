class Solution {
public:
    bool helper(map<char,int>mp) {
        set<int> st;
        for(auto &ip: mp) {
            if(ip.second > 0)
                st.insert(ip.second);
        }
        
        if(1 == st.size())
            return true;
        return false;
    }
    bool equalFrequency(string s) {
        map<char,int>mp;
        for(int idx = 0 ; idx < s.size() ; idx++){
            mp[s[idx]]++;
        }
        
        for(auto &ip : mp) {
            mp[ip.first] -= 1;
            if(helper(mp)) {
                return true;
            }
            mp[ip.first] += 1;
        }
        return false;
    }
};