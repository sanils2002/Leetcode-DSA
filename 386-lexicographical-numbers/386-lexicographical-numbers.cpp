class Solution {
private:
    void helper(int val, int n, vector<int> &res) {
        for(int idx = 0 ; idx <= 9 ; idx++) {
            if(0 == val and 0 == idx)
                continue;
            int x = val * 10 + idx;
            if(x <= n)
                res.push_back(x), helper(x, n, res);
            else
                break;
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        helper(0, n, res);
        return res;
    }
};