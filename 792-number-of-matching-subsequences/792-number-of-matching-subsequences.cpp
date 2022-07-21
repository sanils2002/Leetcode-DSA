class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int counter = 0;
        map<string, bool> mp;
        for(auto w:words) {
            if(mp.end() != mp.find(w)) {
                counter += mp[w];
                continue;
            }
            else {
                mp[w] = 0;
            }
            int jdx = 0;
            for(int idx = 0 ; idx < s.size() ; idx++) {
                if(w[jdx] == s[idx]) {
                    jdx += 1;
                }
                if(jdx == w.size()) {
                    counter++;
                    mp[w] = 1;
                    break;
                }
            }
        }
        return counter;
    }
};