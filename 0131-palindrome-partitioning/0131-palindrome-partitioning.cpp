class Solution {
private:
    bool isPalindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n/2; i++)
            if(s[i] != s[n-i-1])
                return false;
        return true;
    }
    
    void allPalPartUtil(vector<vector<string>>& ans, vector<string>& curr, int start, int n, string s) {
        if(start >= n) {
            ans.push_back(curr);
            return;
        }
        for(int i = start; i < n; i++) {
            if(isPalindrome(s.substr(start, i-start+1))) {
                curr.push_back(s.substr(start, i-start+1));
                allPalPartUtil(ans, curr, i+1, n, s);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> curr;
        allPalPartUtil(ans, curr, 0, n, s);
        return ans;
    }
};