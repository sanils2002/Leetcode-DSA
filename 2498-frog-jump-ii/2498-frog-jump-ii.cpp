class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = stones[1] - stones[0];
        
        for(int i = 2 ; i < stones.size() ; i++) {
            int t = stones[i] - stones[i - 1] + stones[i - 1] - stones[i - 2];
            res = max(res, t);
        }
        
        return res;
    }
};