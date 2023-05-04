class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int longest = 0;
        unordered_set<char> unique_chars;

        int i = 0, j = 0;
        while(i < n && j < n) {
            if(unique_chars.find(s[j]) == unique_chars.end()) {
                unique_chars.insert(s[j]);
                j++;
                longest = max(longest, j - i);
            } 
            else {
                unique_chars.erase(s[i]);
                i++;
            }
        }
    
        return longest;
    }
};