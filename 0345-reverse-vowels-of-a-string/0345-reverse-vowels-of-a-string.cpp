class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
public:
    string reverseVowels(string s) {
        int st = 0;
        int en  = s.size() - 1;
        
        while (st < en) {
            while (st < s.size() && !isVowel(s[st])) {
                st++;
            }
            while (en >= 0 && !isVowel(s[en])) {
                en--;
            }
            if (st < en) {
                swap(s[st++], s[en--]);
            }
        }
        
        return s;
    }
};