class Solution {
public:
    int longestContinuousSubstring(string s) {
        int mx = 1, val = 1;
        for(int idx = 1 ; idx < s.size() ; idx++) {
            if(s[idx] == s[idx-1] + 1)
                val++, mx = max(mx, val);
            else 
                val = 1;
        }
        mx = max(mx, val);
        return mx;
    }
};