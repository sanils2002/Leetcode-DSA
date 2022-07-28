class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s1, t1;
        for(auto &ip : s) {
            s1[ip]++;
        }
        for(auto &ip : t) {
            t1[ip]++;
        }
        
        for(char idx = 'a' ; idx <= 'z' ; idx++) {
            if(s1[idx] != t1[idx])
                return false;
        }
        
        return true;
    }
};