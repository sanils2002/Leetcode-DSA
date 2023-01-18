class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto &x : words) {
            freq[x]++;
        }
        
        vector<pair<string, int>> freqVec;
        for(auto [word, count] : freq) {
            freqVec.push_back({word, count});
        }
        
        sort(freqVec.begin(), freqVec.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        
        vector<string> result;
        for(int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }
    
        return result;
    }
};