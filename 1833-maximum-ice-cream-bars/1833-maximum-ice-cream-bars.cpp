class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        // Count the number of ice cream bars that the boy can buy
        int count = 0;
        for(int i = 0; i < costs.size(); i++) {
            if(coins >= costs[i]) {
                coins -= costs[i];
                count++;
            } 
            else {
                break;
            }
        }
        
        return count;
    }
};