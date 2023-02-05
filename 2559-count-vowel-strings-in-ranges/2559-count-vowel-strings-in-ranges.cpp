class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixCount(words.size() + 1, 0);
        for(int i = 0; i < words.size(); i++) {
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].length() - 1])) {
                prefixCount[i + 1] = prefixCount[i] + 1;
            } 
            else {
                prefixCount[i + 1] = prefixCount[i];
            }
        }

        vector<int> result;
        for(auto& q : queries) {
            result.push_back(prefixCount[q[1] + 1] - prefixCount[q[0]]);
        }
    
        return result;
    }
};