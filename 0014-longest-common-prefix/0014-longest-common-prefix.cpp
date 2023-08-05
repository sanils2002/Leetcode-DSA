class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        
        // Find the shortest string in the array to avoid index out of bounds
        size_t minLen = strs[0].length();
        for(const string& str : strs) {
            minLen = min(minLen, str.length());
        }
        
        // Compare characters at each index among the strings
        for(size_t i = 0; i < minLen; ++i) {
            char currentChar = strs[0][i];
            for(size_t j = 1; j < strs.size(); ++j) {
                if(strs[j][i] != currentChar) {
                    // Found a mismatch, return the common prefix up to this point
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // All strings have the same common prefix up to the shortest length
        return strs[0].substr(0, minLen);
    }
};