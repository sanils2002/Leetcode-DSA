class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        for(int idx = 0 ; idx < names.size() ; idx++) {
            v.push_back({heights[idx], names[idx]});
        }
        
        sort(v.rbegin(), v.rend());
        //reverse(v.begin(), v.end());
        vector<string> res;
        for(auto &ip : v)
            res.push_back(ip.second);
        return res;
    }
};