class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSale = INT_MAX;
        int maxSale = INT_MIN;
        
        for(int idx : prices) {
            minSale = min(minSale, idx);
            //int diff = idx - minSale;
            maxSale = max(maxSale, idx - minSale);
        }
            
        
        return maxSale;
    }
};