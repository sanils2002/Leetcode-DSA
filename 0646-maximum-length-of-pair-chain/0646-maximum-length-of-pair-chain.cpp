class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int res = 0, end = INT_MIN;

        for(auto &p : pairs) {
            if (p[0] > end) {
                res++;
                end = p[1];
            }
        }

        return res;
    }
};