class Solution {
private:
    int update_cur(int cur, vector<int>& a, int p, bool inc=true) {
        if (p > 0 && a[p - 1] == a[p] && a[p - 1] != 0) {
            cur += inc ? 1 : -1;
        }
        if (p < a.size() - 1 && a[p + 1] == a[p] && a[p + 1] != 0) {
            cur += inc ? 1 : -1;
        }
        return cur;
    }
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int cur = 0;
        vector<int> a(n, 0);
        vector<int> ans;
        
        for (auto q : queries) {
            int p = q[0], c = q[1];
            cur = update_cur(cur, a, p, false);
            a[p] = c;
            cur = update_cur(cur, a, p, true);
            ans.push_back(cur);
        }
        
        return ans;
    }
};