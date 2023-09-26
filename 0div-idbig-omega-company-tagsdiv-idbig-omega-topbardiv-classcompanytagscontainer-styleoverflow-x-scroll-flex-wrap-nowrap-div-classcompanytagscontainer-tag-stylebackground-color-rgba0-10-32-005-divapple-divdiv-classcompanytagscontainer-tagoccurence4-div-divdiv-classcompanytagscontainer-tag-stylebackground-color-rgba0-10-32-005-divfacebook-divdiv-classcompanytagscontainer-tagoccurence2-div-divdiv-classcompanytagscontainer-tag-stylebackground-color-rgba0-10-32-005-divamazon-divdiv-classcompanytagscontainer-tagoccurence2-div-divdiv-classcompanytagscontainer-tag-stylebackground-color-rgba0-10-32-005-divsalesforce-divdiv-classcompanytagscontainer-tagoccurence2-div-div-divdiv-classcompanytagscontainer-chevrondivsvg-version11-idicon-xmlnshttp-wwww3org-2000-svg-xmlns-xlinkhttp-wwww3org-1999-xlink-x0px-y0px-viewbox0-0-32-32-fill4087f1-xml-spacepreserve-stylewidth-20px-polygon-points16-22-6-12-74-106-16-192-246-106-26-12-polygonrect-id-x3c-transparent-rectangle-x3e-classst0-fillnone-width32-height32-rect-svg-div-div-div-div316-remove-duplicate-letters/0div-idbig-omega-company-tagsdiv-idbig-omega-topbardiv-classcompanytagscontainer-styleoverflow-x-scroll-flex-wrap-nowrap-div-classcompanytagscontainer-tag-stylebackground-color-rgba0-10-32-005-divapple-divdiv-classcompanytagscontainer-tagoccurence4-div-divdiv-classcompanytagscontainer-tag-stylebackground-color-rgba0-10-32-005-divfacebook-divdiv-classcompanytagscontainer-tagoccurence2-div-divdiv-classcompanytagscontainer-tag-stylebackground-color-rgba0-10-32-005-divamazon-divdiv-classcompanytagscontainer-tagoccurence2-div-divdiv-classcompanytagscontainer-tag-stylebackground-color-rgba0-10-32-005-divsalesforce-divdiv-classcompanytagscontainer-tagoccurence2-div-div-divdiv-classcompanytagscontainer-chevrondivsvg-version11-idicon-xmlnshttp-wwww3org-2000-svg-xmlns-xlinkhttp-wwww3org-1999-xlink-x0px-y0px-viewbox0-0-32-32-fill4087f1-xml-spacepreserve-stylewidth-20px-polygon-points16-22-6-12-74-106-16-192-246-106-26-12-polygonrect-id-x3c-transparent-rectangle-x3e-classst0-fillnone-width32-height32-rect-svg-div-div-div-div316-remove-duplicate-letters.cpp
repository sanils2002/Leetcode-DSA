class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i]] = i;
        }

        string result;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(result.find(c) != string::npos) {
                continue;
            }

            while(!result.empty() && c < result.back() && i < last_occurrence[result.back()]) {
                result.pop_back();
            }
            result.push_back(c);
        }

        return result;
    }
};