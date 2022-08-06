class Solution {
private:
    int chain(string s,int idx, int jdx) {
        while (jdx < s.size() and idx >= 0 and s[idx] == s[jdx]) {
            idx--;
            jdx++;
        }
        return jdx - idx - 1;
    }
public:
    string longestPalindrome(string s) {
        if(1 == s.size()) {
            return s;
        }
        
        int st = 0, len = 0;
        for(int idx = 0 ; idx < s.size() ; idx++) {
            int len1 = chain(s, idx, idx);
            int len2 = chain(s, idx, idx+1);
            
            if(max(len1, len2) > len) {
                len = max(len1, len2);
                st = idx - ((len - 1) / 2);
            }
        }
        
        return s.substr(st, len);
    }
};