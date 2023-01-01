class Solution {
public:
    bool wordPattern(string p, string s) {
        // Split s into words.
        vector<string> words;
        int i = 0;
        while(i < s.size()) {
            int j = i + 1;
            while(j < s.size() && s[j] != ' ') 
                j++;
            words.push_back(s.substr(i, j - i));
            i = j + 1;
        }

        // Check if the number of words in s is the same as the number of letters in p.
        if(words.size() != p.size()) 
            return false;

        // Map each letter in p to a word in s.
        unordered_map<char, string> m;
        for(int i = 0; i < p.size(); i++) {
            if(m.count(p[i]) == 0) {
                // If p[i] is not in the map, add it.
                m[p[i]] = words[i];
            } 
            else {
                // If p[i] is already in the map, check if it maps to the same word as before.
                if(m[p[i]] != words[i]) 
                    return false;
            }
        }

        // Check if there are any two different letters in p that map to the same word.
        for (int i = 0; i < p.size(); i++) {
            for (int j = i + 1; j < p.size(); j++) {
                if (p[i] != p[j] && m[p[i]] == m[p[j]]) 
                    return false;
            }
        }

        return true;
    }
};