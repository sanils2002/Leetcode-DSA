class Solution {
private:
    long binpow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        long res = binpow(a, b / 2);
        res = res * res % mod;
        if (b % 2 == 1) {
            return res * a % mod;
        } 
        else {
            return res;
        }
    }
public:
    long mod = 1000000007L;

    int countAnagrams(string s) {
        int n = s.length();
        vector<long> fact(n + 1);
        
        fact[0] = 1L;
        for(int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % mod;
        }
        vector<string> str;
        string cur;
        
        for(char c : s) {
            if(c == ' ') {
                str.push_back(cur);
                cur.clear();
            } 
            else {
                cur.push_back(c);
            }
        }
        if(!cur.empty()) {
            str.push_back(cur);
        }
        
        long ans = 1;
        for(const string& t : str) {
            int ch[26] = {0};
            for (char c : t) {
                ++ch[c - 'a'];
            }
            long cur = 1;
            for(int a : ch) {
                cur = cur * fact[a] % mod;
            }
            cur = fact[t.length()] * binpow(cur, mod - 2) % mod;
            ans = ans * cur % mod;
        }
        return ans;
    }
};