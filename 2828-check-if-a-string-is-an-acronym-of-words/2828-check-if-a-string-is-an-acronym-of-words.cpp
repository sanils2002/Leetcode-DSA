class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(s.length() != words.size()) {
            return false;
        }
    
        for(size_t i = 0; i < words.size(); ++i) {
            if(s[i] != words[i][0]) {
                return false;
            }
        }
    
        return true;
    }
};