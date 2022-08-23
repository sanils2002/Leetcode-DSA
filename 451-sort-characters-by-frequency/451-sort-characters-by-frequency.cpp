class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;
        
        string ch = "";
        
        for(auto &w : s) {
            mp[w]++;
        }
        for(auto &w : s) {
            pq.push({mp[w], w});
        }
        
        while(!pq.empty()) {
            auto ip = pq.top();
            ch += ip.second;
            pq.pop();
        }
        
        return ch;
    }
};