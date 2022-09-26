class Solution {
private:
    int uf[26];
    int helper(int x) {
        return x == uf[x] ? x : (uf[x] = helper(uf[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for(int idx = 0 ; idx < 26 ; idx++)
            uf[idx] = idx;
        
        for(auto &eq : equations) {
            if('=' == eq[1])
                uf[helper(eq[0] - 'a')] = helper(eq[3] - 'a');
        }
        for(auto &eq : equations) {
            if('!' == eq[1] and helper(eq[0] - 'a') == helper(eq[3] - 'a'))
                return false;
        }
        
        return true;
    }
};