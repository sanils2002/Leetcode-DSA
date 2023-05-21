class Solution {
private:
    bool helper(int i, string s, int n, int sum) {
        if(i == s.length()) {
            if(sum == n)
                return true;
            return false;
        }

        for(int ix = i; ix < s.length(); ix++) {
            if(helper(ix + 1, s, n, sum + stoi(s.substr(i, ix - i + 1))))
                return true;
        }
        
        return false;
    }
    
    bool isPunishment(int n) {
        if(helper(0, to_string(n * n), n, 0))
            return true;
        return false;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if(isPunishment(i))
                ans += i * i;
        }

        return ans;
    }
};