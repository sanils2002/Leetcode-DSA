class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqT, freqWindow;
        for(char c : t) {
            freqT[c]++;
        }
        
        int left = 0, right = 0, count = 0, minLen = INT_MAX, minStart = 0;
        while(right < s.size()) {
            char c = s[right];
            if(freqT.count(c)) {
                freqWindow[c]++;
                if(freqWindow[c] <= freqT[c]) {
                    count++;
                }
            }
            
            right++;
            while(count == t.size()) {
                if(right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }
                char d = s[left];
                if(freqT.count(d)) {
                    freqWindow[d]--;
                    if(freqWindow[d] < freqT[d]) {
                        count--;
                    }
                }
                left++;
            }
        }
    
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};