class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> m1, m2;
        for(char c : s1) 
            ++m1[c];

        int l = 0, r = 0, count = m1.size();
        while(r < s2.size()) {
            char c = s2[r];
            if(m1.count(c)) {
                ++m2[c];
                if(m2[c] == m1[c]) 
                    --count;
            }
            while(count == 0) {
                if(r - l + 1 == s1.size()) 
                    return true;
                c = s2[l];
                if(m1.count(c)) {
                    --m2[c];
                    if(m2[c] < m1[c]) 
                        ++count;
                }
                ++l;
            }
            ++r;
        }
    
        return false;
    }
};