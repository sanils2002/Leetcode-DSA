class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int p1 = 0, p2 = 0;
        while(p1 < word1.size() or p2 < word2.size()) {
            if(p1 < word1.size())
                res += word1[p1++];
            if(p2 < word2.size())
                res += word2[p2++];
        }
        
        return res;
    }
};