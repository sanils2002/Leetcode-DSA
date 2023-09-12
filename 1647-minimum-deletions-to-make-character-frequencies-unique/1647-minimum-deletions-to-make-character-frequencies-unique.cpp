class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> umap;
        for(char c : s)
            umap[c]++;
        
        int val = 0;
        unordered_set<int> uset;
        for(const auto &ip : umap) {
            int freq = ip.second;
            while(uset.count(freq) > 0) {
                freq--;
                val++;
            }
            if(freq > 0)
                uset.insert(freq);
        }
        
        return val;
    }
};