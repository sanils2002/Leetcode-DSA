class Solution {
public:
    int kthFactor(int n, int k) {
        for(int idx = 1 ; idx <= n ; idx++) {
            if(0 == n % idx) {
                k--;
            }
            if(0 == k) {
                return idx;
            }
        }
        return -1;
    }
};