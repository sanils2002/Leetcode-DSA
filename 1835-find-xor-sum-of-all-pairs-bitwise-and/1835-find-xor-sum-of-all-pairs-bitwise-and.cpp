class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x1 = 0, x2 = 0;
        for(auto &x : arr1)
            x1 ^= x;
        for(auto &x : arr2)
            x2 ^= x;
        
        return x1 & x2;
    }
};