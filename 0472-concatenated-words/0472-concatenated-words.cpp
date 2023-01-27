class Solution {
private:
    // Function to check if a word is formed by concatenating other words
    bool isConcatenated(string word, unordered_set<string>& words) {
        int n = word.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && words.count(word.substr(j, i - j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    
        return dp[n];
}
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;
        vector<string> result;
        for(string word : words) {
            dict.insert(word);
        }
        for(string word : words) {
            dict.erase(word);
            if(isConcatenated(word, dict)) {
                result.push_back(word);
            }
            dict.insert(word);
        }
    
        return result;
    }
};