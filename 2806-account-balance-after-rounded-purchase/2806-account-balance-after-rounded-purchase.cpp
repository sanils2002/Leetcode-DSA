class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int sb = ((purchaseAmount + 5) / 10) * 10;
        return 100 - sb;
        
    }
};