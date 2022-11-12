class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(auto idx = n / 2 ; idx >= 1 ; idx--) {
            if(0 == n%idx) {                                                            
                if(s.substr(0, n - idx) == s.substr(idx))
                    return true;           
            }
        }
        return false;
    }
};