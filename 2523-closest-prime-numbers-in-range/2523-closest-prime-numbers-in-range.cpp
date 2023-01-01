class Solution {
public:
    vector<bool> function(int n) {
        vector<bool> prime(n+1, true);
        prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true) {
                for (int j = 2*i; j <= n; j += i) {
                    prime[j] = false;
                }
                if (i*i > n+1) {
                    break;
                }
            }
        }
        return prime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = function(right);
        vector<int> ans;
        for (int n = left; n <= right; n++) {
            if (prime[n]) {
                ans.push_back(n);
            }
        }
        if (ans.size() < 2) {
            return {-1, -1};
        }
        int a = 1;
        int b = 2;
        vector<int> res = {ans[0], ans[1]};
        while (b < ans.size()) {
            if (ans[b] - ans[a] < res[1] - res[0]) {
                res[0] = ans[a];
                res[1] = ans[b];
            }
            a += 1;
            b += 1;
        }
        return res;
    }
};