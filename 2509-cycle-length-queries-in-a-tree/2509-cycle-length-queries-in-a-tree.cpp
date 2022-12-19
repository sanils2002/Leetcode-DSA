class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &q : queries) {
            int x = q[0], y = q[1], cnt = 1;
            while (x != y) {
                if(x < y)
                    swap(x, y);
                x /= 2;
                cnt++;
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};