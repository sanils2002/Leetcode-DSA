class Solution {
private:
    void generateParentheses(int n, int open, int close, string str, vector<string>& res) {
        if(open == n && close == n) {
            res.push_back(str);
            return;
        }
        if(open < n) {
            generateParentheses(n, open + 1, close, str + '(', res);
        }
        if(close < open) {
            generateParentheses(n, open, close + 1, str + ')', res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParentheses(n, 0, 0, "", res);
        return res;
    }
};