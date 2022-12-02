class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        
        set<char> s1, s2;
        vector<int> freq1(26, 0), freq2(26, 0);
        
        for(int idx = 0 ; idx < word1.size() ; idx++) {
            s1.insert(word1[idx]);
            s2.insert(word2[idx]);
            freq1[word1[idx] - 'a']++;
            freq2[word2[idx] - 'a']++;
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        if(s1 == s2 and freq1 == freq2)
            return true;
        return false;
    }
};