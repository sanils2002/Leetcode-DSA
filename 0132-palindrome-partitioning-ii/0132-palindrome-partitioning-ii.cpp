class Solution {
private:
    bool isPalindrome(const string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
    
        return true;
}
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> minCuts(n, INT_MAX);

        for(int i = 0; i < n; ++i) {
            minCuts[i] = i; // initialize with the worst case (maximum cuts)
            for(int j = 0; j <= i; ++j) {
                if(s[j] == s[i] && (i - j <= 1 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    if(j == 0) {
                        minCuts[i] = 0; // s[0:i] is a palindrome, no cuts needed
                    } 
                    else {
                        minCuts[i] = min(minCuts[i], minCuts[j - 1] + 1);
                    }
                }
            }
        }

        return minCuts[n - 1];
    }
};