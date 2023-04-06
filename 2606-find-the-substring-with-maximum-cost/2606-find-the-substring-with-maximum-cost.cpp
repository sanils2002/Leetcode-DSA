class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26);
        int max_cost = 0, cost = 0;
        iota(begin(v), end(v), 1);
        for(int i  = 0; i < chars.size(); ++i)
            v[chars[i] - 'a'] = vals[i];
    
        for(char ch : s) {
            cost = max(0, cost + v[ch - 'a']);
            max_cost = max(max_cost, cost);
        }
    
        return max_cost;
    }
};