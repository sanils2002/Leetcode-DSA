class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int idx = 2 ; idx < n ; idx++) {
            cost[idx] += min(cost[idx-1], cost[idx-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};