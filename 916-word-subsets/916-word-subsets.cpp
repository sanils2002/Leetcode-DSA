class Solution {
private:
    int countChar(string s, char ch) {
        int new_cnt = 0;
        for(char &x : s) {
            if(ch == x)
                new_cnt++;
        }
        return new_cnt;
    }
protected:
    bool newSubset(string s, vector<int> &freq) {
        for(char x = 'a' ; x < 'z' ; x++) {
            if(countChar(s, x) < freq[x - 'a'])
                return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freqWord2(26, 0);
        vector<string> res;
        
        for(string &s : words2) {
            for(char x = 'a' ; x < 'z' ; x++)
                freqWord2[x - 'a'] = max(countChar(s, x), freqWord2[x - 'a']);
        }
        
        for(string &s : words1) {
            if(newSubset(s, freqWord2))
                res.push_back(s);
        }
        
        return res;
    }
};