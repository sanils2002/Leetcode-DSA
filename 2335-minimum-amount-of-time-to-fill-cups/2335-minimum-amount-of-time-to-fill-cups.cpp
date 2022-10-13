class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        //Type of cups with more in quantity will be left which will be filled at a time once
        //All the path 2 cups will be filled any iteration only when we have odd number of cups
        if(amount[2] >= amount[1] + amount[0])
            return amount[2];
        int sum = amount[2] + amount[1] + amount[0];
        return (sum / 2) + (sum % 2);
    }
};