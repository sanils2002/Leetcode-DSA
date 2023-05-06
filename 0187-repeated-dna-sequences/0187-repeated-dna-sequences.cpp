class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq; // keep track of frequency of each 10-letter substring
        vector<string> result; // to store the repeated substrings
        
        if(s.size() < 10)
            return result;
        
        // check each 10-letter substring in the sequence
        for(int i = 0; i <= s.size() - 10; i++) {
            string sub = s.substr(i, 10);
            freq[sub]++;
            
            // add to result if this is the second time we've seen it
            if(freq[sub] == 2) {
                result.push_back(sub);
            }
        }
        
        return result;
    }
};