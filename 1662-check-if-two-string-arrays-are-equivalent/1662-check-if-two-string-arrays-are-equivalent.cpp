class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x = "", y = "";
        
        for(auto &w1 : word1) {
            x += w1;
        }
        for(auto &w2 : word2) {
            y += w2;
        }
        
        return x == y;
       
    }
};