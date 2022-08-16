class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap(26);
        
        for(int idx = 0 ; idx < s.size() ; idx++) {
            umap[s[idx]]++;
        }
        
        for(int idx = 0 ; idx < s.size() ; idx++) {
            if(1 == umap[s[idx]])
                return idx;
        }
        
        return -1;
    }
};