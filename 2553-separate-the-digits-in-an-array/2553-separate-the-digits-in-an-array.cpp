class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        for(auto &x : nums) {
            string z = to_string(x);
            for(auto &c : z) {
                v.push_back(c - '0');
            }
        }
        return v;
    }
};