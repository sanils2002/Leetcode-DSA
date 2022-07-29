class Solution {
private:
    string PatternGenerator(string word) {
        map<char, int> mp;
        int new_cnt = 0, nWord = word.size();
        
        string pattern = "";
        
        for(int idx = 0 ; idx < nWord ; idx++) {
            if(!mp.count(word[idx])) {
                new_cnt++;
                mp[word[idx]] = new_cnt;
            }
            pattern += char('0' + mp[word[idx]]);
        }
        return pattern;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int nPattern = pattern.size();
        vector<string> key;
        
        string repl = PatternGenerator(pattern);
        for(string &letter : words) {
            string temp = PatternGenerator(letter);
            int idx = 0;
            while(idx < nPattern) {
                if(repl[idx] != temp[idx])
                    break;
                idx++;
            }
            if(nPattern == idx)
                key.push_back(letter);
        }
        
        return key;
    }
};