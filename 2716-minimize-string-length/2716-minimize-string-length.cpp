class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char,int> um;
        for(int i = 0 ; i < s.size() ; i++)
            um[s[i]]++;
        
        return um.size();
    }
};