class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int idx = 0 ; idx <= (s.size() - 1) / 2 ; idx++) {
            char x = s[idx];
            s[idx] = s[s.size() - idx - 1];
            s[s.size() - idx - 1] = x;
        }
    }
};