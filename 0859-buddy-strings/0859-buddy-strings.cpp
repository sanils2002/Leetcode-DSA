class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
    
        if(s == goal) {
            unordered_set<char> seen;
            for(char ch : s) {
                if(seen.count(ch) > 0) {
                    return true;
                }
                seen.insert(ch);
            }
            return false;
        }
    
        vector<int> diffs;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                diffs.push_back(i);
            }
        }
    
        return diffs.size() == 2 && s[diffs[0]] == goal[diffs[1]] && s[diffs[1]] == goal[diffs[0]];
    }
};