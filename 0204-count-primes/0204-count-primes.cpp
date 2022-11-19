class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n+1,true);
        prime[0] = prime[1] = false;
        for(int idx = 2 ; idx < n ; idx++) { 
            if(prime[idx]) {
                cnt++;
                for(int jdx = 2 * idx ; jdx < n ; jdx += idx) {
                    prime[jdx]=0;
                }
            }
        }
        return cnt;
    }
};