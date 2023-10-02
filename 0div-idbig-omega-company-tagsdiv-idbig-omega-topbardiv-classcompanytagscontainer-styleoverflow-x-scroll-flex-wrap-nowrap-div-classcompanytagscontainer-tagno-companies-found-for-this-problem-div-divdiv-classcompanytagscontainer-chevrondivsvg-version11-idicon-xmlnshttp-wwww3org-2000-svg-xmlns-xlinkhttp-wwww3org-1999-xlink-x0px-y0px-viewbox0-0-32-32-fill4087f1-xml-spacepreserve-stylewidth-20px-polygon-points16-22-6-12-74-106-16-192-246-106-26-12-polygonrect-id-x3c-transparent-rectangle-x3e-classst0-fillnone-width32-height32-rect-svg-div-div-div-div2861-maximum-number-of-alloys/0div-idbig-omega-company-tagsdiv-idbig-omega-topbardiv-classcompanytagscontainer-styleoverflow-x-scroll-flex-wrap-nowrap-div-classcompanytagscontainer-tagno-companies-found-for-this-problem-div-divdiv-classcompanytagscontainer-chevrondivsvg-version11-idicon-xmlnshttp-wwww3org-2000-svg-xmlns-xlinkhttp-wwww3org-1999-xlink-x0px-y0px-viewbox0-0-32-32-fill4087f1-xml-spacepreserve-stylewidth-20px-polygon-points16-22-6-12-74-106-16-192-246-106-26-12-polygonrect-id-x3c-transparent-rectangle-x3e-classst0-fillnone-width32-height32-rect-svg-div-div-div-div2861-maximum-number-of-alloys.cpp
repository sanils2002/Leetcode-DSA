class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        vector<vector<long long>> required_stock(k, vector<long long>(n, 0));
        
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                required_stock[i][j] = (long long)composition[i][j] * (long long)cost[j];
            }
        }
        
        long long left = 0, right = 1e9, result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            bool can_create = false;
            
            for (int machine = 0; machine < k; ++machine) {
                long long total_cost = 0;
                for (int i = 0; i < n; ++i) {
                    long long diff = mid * composition[machine][i] - stock[i];
                    if (diff > 0) total_cost += diff * cost[i];
                }
                
                if (total_cost <= budget) {
                    can_create = true;
                    break;
                }
            }
            
            if (can_create) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};