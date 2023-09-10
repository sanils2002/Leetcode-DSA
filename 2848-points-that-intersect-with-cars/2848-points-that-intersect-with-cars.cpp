class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> s;
        for(auto &ip : nums) {
            int st = ip[0], en = ip[1];
            for(int i = st ; i <= en ; i++)
                s.insert(i);
        }
        return s.size();
    }
};