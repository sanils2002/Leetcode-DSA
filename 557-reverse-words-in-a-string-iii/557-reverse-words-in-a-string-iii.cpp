class Solution {
public:
    string reverseWords(string s) {
       for(int st  = 0, en = 0 ; en <= s.size() ; en++) {
            if(' ' == s[en] or '\0' == s[en]) {
                reverse(s.begin() + st, s.begin() + en);
                st = en + 1;
            }
        }
        return s;
    }
};