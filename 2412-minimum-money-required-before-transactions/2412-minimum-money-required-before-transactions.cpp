class Solution {
private:
    long long max(long long x, long long y) {
        if(x > y)
            return x;
        else 
            return y;
    }
    long long min(long long x, long long y) {
        if(x > y)
            return y;
        else 
            return x;
    }
    
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long money = 0;
        for(int idx = 0 ; idx < transactions.size() ; idx++)
            money = max(money, min(transactions[idx][0], transactions[idx][1]));
        for(int idx = 0 ; idx < transactions.size() ; idx++)
            money += max(0, transactions[idx][0] - transactions[idx][1]);
        return money;
    }
};