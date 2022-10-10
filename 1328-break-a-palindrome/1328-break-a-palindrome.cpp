class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(1 == n)
            return "";
        
        for(int idx = 0 ; idx < n / 2 ; idx++) {
            if('a' != s[idx]) {
                s[idx] = 'a';
                return s;
            } 
        }
        s[n - 1] = 'b';
        return s;
    }
};