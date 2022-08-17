class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, int> umap;
        
        for(int idx = 0 ; idx < words.size() ; idx++) {
            string uniq;
            for(int jdx = 0 ; jdx < words[idx].size() ; jdx++)
                uniq += morse[words[idx][jdx] - 'a'];
            umap[uniq] = 1;
        }
        
        return umap.size();
    }
};